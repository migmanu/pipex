/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:26:47 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/27 18:41:37 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipe_cmds(t_pipex *data, char *cmd, char **env)
{
	printf("pipe_cmds init!\n");
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	data->pipe_read = p_fd[0];
	data->pipe_write = p_fd[1];
	pid = fork();
	if (pid == -1)
		handle_error(data, "-i infile");
	if (pid == 0)
	{
		close(data->pipe_read);
		dup2(data->pipe_write, 1);
		if (exec(cmd, env) == -1)
		{
			ft_putendl_fd("exec failed", 2);
			handle_error(data, "-i infile read");
		}
	}
	else
	{
		close(data->pipe_write);
		dup2(data->pipe_read, 0);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	int		i;
	t_pipex	*data;

	data = malloc(sizeof(t_pipex));
	if (data == NULL)
		return (-1);
	if (argc < 5)
		handle_error(data "none");
	i = 2;
	// TODO: add here_doc
	data->infile = open_file(argv[1], 0);
	data->outfile = open_file(argv[argc - 1], 1);
	dup2(data->infile, 0);
	close(data->infile);
	while (i < argc - 2)
		pipe_cmds(data, argv[i++], env);
	dup2(data->outfile, 1);
	close(data->outfile);
	if (exec(argv[argc - 2], env) == -1)
		handle_error(data, "read");
	close(data->pipe_read);
}
