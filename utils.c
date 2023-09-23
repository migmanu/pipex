/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:03 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/23 15:05:01 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			return (path);
		free(path);
		i++;
	}
	i = 0;
	while (path_vec[i])
		free(path_vec[i++]);
	free(path_vec);
}

void	exec(char *cmd, char *env[])
{

}

void	error(void)
{
		perror("error");
		exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *env[])
{
	get_path("ls", env);
	return (0);
}
