/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:41:20 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:41:23 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_find_cmd_vars
{
	char	**paths;
	char	*full_path;
	char	*temp_path_segment;
	int		i;
}	t_find_cmd_vars;

typedef struct s_pipex_vars
{
	int		pipefd[2];
	int		infile_fd;
	int		outfile_fd;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex_vars;

void	ft_free_str_array(char **arr);
char	**parse_cmd_args(char *cmd_str);
char	*find_cmd_path(char *cmd_name, char **envp);
void	error_exit(const char *msg);
void	execute_child_one(char **argv, char **envp, int *pipefd);
void	execute_child_two(char **argv, char **envp, int *pipefd);

#endif
