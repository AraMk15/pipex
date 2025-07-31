/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:42:22 by armkrtch          #+#    #+#             */
/*   Updated: 2025/07/26 19:42:25 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free_str_array(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	get_command_path_helper(char **envp, char ***paths)
{
	while (*envp && ft_strncmp("PATH=", *envp, 5) != 0)
		envp++;
	if (!*envp)
		return (0);
	*paths = ft_split(*envp + 5, ':');
	if (!*paths)
		return (0);
	return (1);
}

char	**parse_cmd_args(char *cmd_str)
{
	char	**cmd_args;

	if (cmd_str == NULL || *cmd_str == '\0')
		return (NULL);
	cmd_args = ft_split(cmd_str, ' ');
	if (!cmd_args)
		return (NULL);
	return (cmd_args);
}

static char	*handle_direct_path(char *cmd_name)
{
	if (ft_strchr(cmd_name, '/') != NULL)
	{
		if (access(cmd_name, X_OK) == 0)
			return (ft_strdup(cmd_name));
		else
			return (NULL);
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd_name, char **envp)
{
	t_find_cmd_vars	v;
	char			*direct_path;

	direct_path = handle_direct_path(cmd_name);
	if (direct_path != NULL)
		return (direct_path);
	if (!get_command_path_helper(envp, &v.paths))
		return (NULL);
	v.i = 0;
	while (v.paths[v.i])
	{
		v.temp_path_segment = ft_strjoin(v.paths[v.i], "/");
		if (!v.temp_path_segment)
			return (ft_free_str_array(v.paths), NULL);
		v.full_path = ft_strjoin(v.temp_path_segment, cmd_name);
		free(v.temp_path_segment);
		if (!v.full_path)
			return (ft_free_str_array(v.paths), NULL);
		if (access(v.full_path, X_OK) == 0)
			return (ft_free_str_array(v.paths), v.full_path);
		free(v.full_path);
		v.i++;
	}
	return (ft_free_str_array(v.paths), NULL);
}
