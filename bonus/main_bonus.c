/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:26:47 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/01 18:27:08 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	pipe_cmds(t_pipex **data, char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	(*data)->pipe_read = p_fd[0];
	(*data)->pipe_write = p_fd[1];
	pid = fork();
	if (pid == -1)
		handle_error();
	if (pid == 0)
	{
		close((*data)->pipe_read);
		(*data)->pipe_read = -1;
		dup2((*data)->pipe_write, 1);
		if (exec(cmd, env) == -1)
			handle_error();
	}
	else
	{
		close((*data)->pipe_write);
		(*data)->pipe_write = -1;
		dup2((*data)->pipe_read, 0);
	}
}

int	check_cmds(int argc, char *argv[], char *env[])
{
	char	**path_vec;
	char	*path;
	int		i;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i = 3;
	if (argc < 5)
		return (-1);
	while (i < argc - 1)
	{
		path_vec = ft_split(argv[i++], ' ');
		path = get_path(path_vec[0], env);
		ft_free_vec(path_vec);
		if (!path)
		{
			i = -1;
		}
		if (i == -1)
			return (-1);
		free(path);
		path = NULL;
	}
	free(path);
	return (0);
}

void	input_here_doc(t_pipex **data, char *argv[])
{
	char	*line;

	close((*data)->pipe_read);
	(*data)->pipe_read = -1;
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, argv[2], (ft_strlen(argv[2]) - 1)) == 0)
		{
			free(line);
			exit(0);
		}
		free(line);
	}
	close((*data)->pipe_write);
	(*data)->pipe_write = -1;
}

void	manage_here_doc(t_pipex **data, int argc, char *argv[])
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1*)
		exit(0);
	(*data)->pipe_read = p_fd[0];
	(*data)->pipe_write = p_fd[1];
	close(p_fd[0]);
	close(p_fd[1]);
	close((*data)->outfile);
	(*data)->outfile = open_file(argv[argc - 1], 2);
	dup2((*data)->infile, 0);
	close((*data)->infile);
	close((*data)->outfile);
	(*data)->outfile = -1;
	(*data)->infile = -1;
	pid = fork();
	if (pid == -1)
		handle_error();
	if (pid == 0)
		input_here_doc(&data, argv);
	if (pid != 0)
	{
		close((*data)->pipe_write);
		dup2((*data)->pipe_read, 0);
		wait(NULL);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex *data;
	int		i;

	if (check_cmds(argc, argv, env) < 0)
		exit(0);
	data = initialize_data(argc, argv);
	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		manage_here_doc(&data, argc, argv);
		i = 3;
	}
	else
	{
		dup2(data->infile, 0);
		close(data->infile);
		data->infile = -1;
	}
	while (i < argc - 2)
		pipe_cmds(&data, argv[i++], env);
	dup2(data->outfile, 1);
	close(data->outfile);
	if (exec(argv[argc - 2], env) == -1)
		handle_error();
	close(data->pipe_read);
	free(data);
}
