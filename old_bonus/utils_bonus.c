/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:03 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/01 18:09:58 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

extern t_pipex	*data;

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
		{
			ft_free_vec(path_vec);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_vec(path_vec);
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
	if (file_type == 2)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	return (fd);
}

t_pipex	*initialize_data(int argc, char *argv[])
{
	t_pipex *data;

	data = malloc(sizeof(t_pipex));
	if (data == NULL)
		exit(1);
	data->infile = open_file(argv[1], 0);
	if (!data->infile)
		exit(1);
	data->outfile = open_file(argv[argc - 1], 1);
	if (!data->outfile)
	{
		close(data->infile);
		exit(1);
	}
	data->pipe_read = -1;
	data->pipe_write = -1;
	return (data);
}

int	exec(char *cmd_str, char *env[])
{
	char	**cmd;
	char	*path;

	cmd = ft_split(cmd_str, ' ');
	path = get_path(cmd[0], env);
	if (!path)
	{
		ft_free_vec(cmd);
		return (-1);
	}
	if (execve(path, cmd, env) == -1)
	{
		ft_free_vec(cmd);
		free(path);
		return (-1);
	}
	ft_free_vec(cmd);
	free(path);
	return (1);
}

void	handle_error(void)
{
	if (data != NULL)
	{
		if (data->infile != -1)
			close(data->infile);
		if (data->outfile != -1)
			close(data->outfile);
		if (data->pipe_read != -1)
			close(data->pipe_read);
		if (data->pipe_write != -1)
			close(data->pipe_write);
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
