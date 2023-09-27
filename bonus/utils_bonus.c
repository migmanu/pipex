/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:03 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/27 18:48:19 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	open_file(char *file, int file_type)
{
	int	fd;

	if (file_type == 0)
	{
		fd = open(file, O_RDONLY, 0777);
	}
	if (file_type == 1)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	return (fd);
}

int	exec(char *cmd_str, char *env[])
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
		return (-1);
	}
	if (execve(path, cmd, env) == -1)
	{
		return (-1);
	}
	return (1);
}

void	handle_error(t_pipex *data, char *cmd)
{
	if (data != NULL)
	{
		if (ft_strncmp(cmd, "-i infile read", 14) == 0)
		{
			close(data->outfile);
			close(data->pipe_write);
		}
		if (ft_strncmp(cmd, "-i infile", 9) == 0)
		{
			close(data->outfile);
			close(data->pipe_read);
			close(data->pipe_write);
		}
		if (ft_strncmp(cmd, "read", 4) == 0)
			close(data->pipe_read);
		free(data);
		data = NULL;
	}
	perror("Error in function. Exiting");
	exit(EXIT_FAILURE);
}
/*
int	main(int argc, char *argv[], char *env[])
{
	exec("pwd", env);
	return (0);
}*/
