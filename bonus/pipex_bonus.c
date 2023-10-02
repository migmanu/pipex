/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:45:31 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/02 18:30:48 by jmigoya-         ###   ########.fr       */
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
	if (pipe(data->pipe[0]) || pipe(data->pipe[1]) == -1)
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
	if (data->infile < 0 || data->outfile < 0)
	{
			ft_putendl_fd("Open function failed", 2);
			clean_fds(data);
			return (OPEN_ERR);
	}
	return (0);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex data;

	printf("%s", env[1]);
	if (check_args(argc, argv) != 0)
		return (ARG_ERR);
	fill_data(&data, argc, argv);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		//open_here_doc(data, argc, argv, env);
	}
	else
	{

	}

	return (0);
}
