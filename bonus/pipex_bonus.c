/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:45:31 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/03 19:29:57 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	clean_fds(t_pipex *data)
{
	close(data->infile);
	close(data->outfile);
	close(data->pipe[0][0]);
	close(data->pipe[0][1]);
	close(data->pipe[1][0]);
	close(data->pipe[1][1]);
}

int	fill_data(t_pipex *data, int argc, char *argv[])
{
	if (pipe(data->pipe[0]) == -1 || pipe(data->pipe[1]) == -1)
	{
		ft_putendl_fd("Pipe failed", 2);
		clean_fds(data);
		return (PIPE_ERR);
	}
	data->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		data->infile = open(HERE_DOC, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (data->outfile < 0)
		{
			ft_putendl_fd("Open function failed", 2);
			clean_fds(data);
			return (OPEN_ERR);
		}
		return (0);
	}
	data->infile = open(argv[1], O_RDONLY, 0777);
	if (data->infile < 0 || data->outfile < 0)
	{
		clean_fds(data);
		return (OPEN_ERR);
	}
	return (0);
}

void	pipe_cmds(t_pipex *data, char *argv[], char *env[])
{
	pid_t	pid;
	int		i;
	int		use_pipe;

	use_pipe = 0;
	i = 2 + data->here_doc;
	while (i < data->argc - 2)
	{
		pid = fork();
		if (pid == 0)
		{
			exec(data, argv[i], env, use_pipe);
		}
		else
		{
			wait(NULL);
			exec(data, argv[i], env, use_pipe);
		}
		i++;
		if (++use_pipe > 1)
			use_pipe = 0;
	}
}

int	main(int argc, char *argv[])
{
	t_pipex	data;

	if (check_args(argc, argv) != 0)
		return (ARG_ERR);
	printf("args checked\n");
	fill_data(&data, argc, argv);
	printf("data filled\n");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		do_here_doc(&data, argc, argv);
	}
	else
	{
		dup2(data.infile, 0);
		close(data.infile);
	}
	//while (i < argc - 2)
	//	pipe_cmds(&data, argv[i++], env);
	return (0);
}
