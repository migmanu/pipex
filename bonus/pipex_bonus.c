/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:45:31 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/02 20:40:08 by jmigoya-         ###   ########.fr       */
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
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		data->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (data->outfile < 0)
		{
			ft_putendl_fd("Open function failed", 2);
			clean_fds(data);
			return (OPEN_ERR);
		}
		return (0);
	}
	data->infile = open(argv[1], O_RDONLY, 0777);
	data->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (0);
}

int	do_here_doc(t_pipex *data, int argc, char *argv[])
{
	ft_putendl_fd("do_here_doc init", 2);
	pid_t pid;
	char *line;

	printf("%d", argc);
	pid = fork();
	if (pid == -1)
	{
		clean_fds(data);
		exit(FORK_ERR); // TODO handle_error
	}
	if (pid == 0)
	{
		while (get_next_line(&line))
		{
			dup2(data->outfile, 1);
			ft_putendl_fd("line found", 2);
			ft_putendl_fd(line, 2);
			if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
				exit(0);
			ft_putstr_fd(line, 1);
			free(line);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
	
}

int	main(int argc, char *argv[])
{
	t_pipex data;

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

	}

	return (0);
}
