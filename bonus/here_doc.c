/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:01:43 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/03 19:30:19 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	read_here_doc(t_pipex *data, char *argv[])
{
	char	*line;

	while (1)
	{
		get_next_line(&line);
		ft_putendl_fd("line found", 2);
		ft_putendl_fd(line, 2);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			ft_putendl_fd("match", 2);
			free(line);
			exit(EXIT_SUCCESS);
		}
		write(data->infile, line, ft_strlen(line));
		free(line);
	}
	return (1);
}

int	do_here_doc(t_pipex *data, int argc, char *argv[])
{
	printf("%d", argc);
	data->here_doc = 1;
	ft_putendl_fd("do_here_doc init", 2);
	read_here_doc(data, argv);
	dup2(data->infile, 0);
	close(data->infile);
	return (0);
}
