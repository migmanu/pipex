/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:04:13 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/02 20:38:31 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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

int	check_args(int argc, char *argv[])
{
	if (argc < 5)
	{
		ft_putendl_fd("Not enough args. Use: ./pipex file1 cmd1 cmd2 file2", 2);
		return (ARG_ERR);
	}
	if (ft_strnstr(argv[1], "here_doc", 8) == 0)
		return (0);
	if (open(argv[1], 0, 0) < 0)
	{
		ft_putendl_fd("Wrong input file", 2);
		return (ARG_ERR);
	}
	return (0);
}

int	get_next_line(char **line)
{
	char	*buff;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buff = malloc(sizeof(10000));
	if (!buff)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buff[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buff[i] = '\n';
	buff[++i] = '\0';
	*line = malloc(sizeof(i));
	ft_memcpy(*line, buff, i);
	free(buff);
	return (r);
}
