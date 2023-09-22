/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:26:47 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/22 19:47:03 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec()
{

}

void	child(char *argv[], int fd[], char *env[])
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	//execute
}

void	parent(char *argv[], int fd[], char *env[])
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENOL);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	// execute
}

int main(int argc, char *argv[], char *env[])
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		return (2);
	if (pipe(fd) == -1)
		return (2);
	pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
		child(argv, fd, env);
	else
		parent(argv, fd, env);
}
