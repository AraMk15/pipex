/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:41:02 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:41:06 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	execute_child_one(char **argv, char **envp, int *pipefd)
{
	int		infile;
	char	**cmd;
	char	*path;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_exit("Infile open error");
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	cmd = ft_split(argv[2], ' ');
	path = find_cmd_path(cmd[0], envp);
	if (!path)
	{
		ft_free_str_array(cmd);
		error_exit("Command not found");
	}
	execve(path, cmd, envp);
	perror("execve");
	free(path);
	ft_free_str_array(cmd);
	exit(EXIT_FAILURE);
}

void	execute_child_two(char **argv, char **envp, int *pipefd)
{
	int		outfile;
	char	**cmd;
	char	*path;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_exit("Outfile open error");
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[1]);
	cmd = ft_split(argv[3], ' ');
	path = find_cmd_path(cmd[0], envp);
	if (!path)
	{
		ft_free_str_array(cmd);
		error_exit("Command not found");
	}
	execve(path, cmd, envp);
	perror("execve");
	free(path);
	ft_free_str_array(cmd);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_vars	vars;

	if (argc != 5)
		error_exit("./pipex file1 cmd1 cmd2 file2");
	if (pipe(vars.pipefd) == -1)
		error_exit("pipex: ");
	vars.pid1 = fork();
	if (vars.pid1 < 0)
		error_exit("fork");
	else if (vars.pid1 == 0)
		execute_child_one(argv, envp, vars.pipefd);
	vars.pid2 = fork();
	if (vars.pid2 < 0)
		error_exit("fork");
	else if (vars.pid2 == 0)
		execute_child_two(argv, envp, vars.pipefd);
	close(vars.pipefd[0]);
	close(vars.pipefd[1]);
	waitpid(vars.pid2, NULL, 0);
	waitpid(vars.pid1, NULL, 0);
}
