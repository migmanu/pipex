/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:01:43 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/03 14:33:07 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	read_here_doc(t_pipex *data, char *argv[])
{
	char *line;

	dup2(data->outfile, 1);
	close(data->infile);
	while (get_next_line(&line))
	{
		ft_putendl_fd("line found", 2);
		ft_putendl_fd(line, 2);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		write(data->pipe[0][1], line, ft_strlen(line));
		free(line);
	}
	return (0);
}

int	do_here_doc(t_pipex *data, int argc, char *argv[])
{
	ft_putendl_fd("do_here_doc init", 2);
	pid_t pid;

	printf("%d", argc);
	pid = fork();
	if (pid == -1)
	{
		clean_fds(data);
		exit(FORK_ERR); // TODO handle_error
	}
	if (pid == 0)
	{
		read_here_doc(data, argv);
	}
	else
	{
		wait(NULL);
	}
	return (0);
	
}
