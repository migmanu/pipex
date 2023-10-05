/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:03 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/05 14:26:29 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_path(char *cmd, char *env[])
{
	char	**path_vec;
	char	*tmp_path;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	path_vec = ft_split(env[i] + 5, ':');
	i = 0;
	while (path_vec[i])
	{
		tmp_path = ft_strjoin("/", cmd);
		path = ft_strjoin(path_vec[i], tmp_path);
		free(tmp_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = 0;
	while (path_vec[i])
		free(path_vec[i++]);
	free(path_vec);
	return (NULL);
}

void	exec(char *cmd_str, char *env[])
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(cmd_str, ' ');
	path = get_path(cmd[0], env);
	i = 0;
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		error(CMD_NOT_FOUND);
	}
	if (execve(path, cmd, env) == -1)
		error(CMD_NOT_FOUND);
}

void	error(int err)
{
	if (err ==  CMD_NOT_FOUND)
	{
		perror("Command not found. Path:");	
		exit(CMD_NOT_FOUND);
	}
	else if (err == ERROR)
	{
		perror("Input file not found");	
		exit(1);
	}
	else
	{
		perror("Error in function. Exiting");
		exit(EXIT_FAILURE);
	}
}
/*
int	main(int argc, char *argv[], char *env[])
{
	exec("pwd", env);
	return (0);
}*/
