/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:26:47 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/30 23:23:48 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

t_pipex	*g_data;

void	pipe_cmds(char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	g_data->pipe_read = p_fd[0];
	g_data->pipe_write = p_fd[1];
	pid = fork();
	if (pid == -1)
		handle_error();
	if (pid == 0)
	{
		close(g_data->pipe_read);
		g_data->pipe_read = -1;
		dup2(g_data->pipe_write, 1);
		if (exec(cmd, env) == -1)
			handle_error();
	}
	else
	{
		close(g_data->pipe_write);
		g_data->pipe_write = -1;
		dup2(g_data->pipe_read, 0);
	}
}

int	check_cmds(int argc, char *argv[], char *env[])
{
	char	**path_vec;
	int		i;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i = 3;
	if (argc < 5)
		return (-1);
	while (i < argc - 1)
	{
		path_vec = ft_split(argv[i++], ' ');
		if (!get_path(path_vec[0], env))
		{
			i = 0;
			while (path_vec[i])
				free(path_vec[i++]);
			free(path_vec);
			path_vec = NULL;
			return (-1);
		}
	}
	free(path_vec);
	path_vec = NULL;
	return (0);
}

void	input_here_doc(char *argv[])
{
	char	*line;

	close(g_data->pipe_read);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, g_data->pipe_write);
		free(line);
	}
	close(g_data->pipe_write);
}

void	manage_here_doc(int argc, char *argv[])
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	g_data->pipe_read = p_fd[0];
	g_data->pipe_write = p_fd[1];
	close(g_data->outfile);
	g_data->outfile = open_file(argv[argc - 1], 2);
	pid = fork();
	if (pid == -1)
		handle_error();
	if (pid == 0)
	{
		input_here_doc(argv);
	}
	else
	{
		close(g_data->pipe_write);
		dup2(g_data->pipe_read, 0);
		wait(NULL);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	int		i;

	if (check_cmds(argc, argv, env) < 0)
		exit(1);
	initialize_g_data(argc, argv);
	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		manage_here_doc(argc, argv);
	}
	else
	{
		dup2(g_data->infile, 0);
		close(g_data->infile);
	}
	g_data->infile = -1;
	while (i < argc - 2 && g_data->control != -1)
		pipe_cmds(argv[i++], env);
	dup2(g_data->outfile, 1);
	close(g_data->outfile);
	if (exec(argv[argc - 2], env) == -1 && g_data->control != -1)
		handle_error();
	close(g_data->pipe_read);
}
