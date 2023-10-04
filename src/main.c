/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:26:47 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/03 19:39:49 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child(char *argv[], int fd[], char *env[])
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(filein, STDIN_FILENO);
	close(filein);
	close(fd[0]);
	exec(argv[2], env);
}

void	parent(char *argv[], int fd[], char *env[])
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	close(fd[1]);
	exec(argv[3], env);
}

int	main(int argc, char *argv[], char *env[])
{
	int		fd[2];
	int		test_file;
	pid_t	pid;

	test_file = open(argv[1], 0, 0);
	if (test_file < 0)
		return (1);
	close(test_file);
	if (argc != 5)
		error();
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		child(argv, fd, env);
	else
		parent(argv, fd, env);
}
