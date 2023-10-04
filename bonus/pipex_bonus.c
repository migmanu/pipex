/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:45:31 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/04 13:04:21 by migmanu          ###   ########.fr       */
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
	free(data);
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

void	exec(char *cmd_str, char *env[])
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(cmd_str, ' ');
	path = get_path(cmd[0], env);
	ft_putendl_fd("exec cmd:", 2);
	ft_putendl_fd(cmd[0], 2);
	i = 0;
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		exit(1);
	}
	if (execve(path, cmd, env) == -1)
		exit(1);
}

void	pipe_cmds(t_pipex *data, char *argv[], char *env[])
{
	ft_putendl_fd("pipe_cmds init", 2);
	pid_t	pid;
	int		i;
	int		use_pipe;

	pipe(data->pipe[0]);
	use_pipe = 0;
	i = 2 + data->here_doc;
	while (i < data->argc - 2)
	{
		ft_putendl_fd("while init i:", 2);
		ft_putnbr_fd(i, 2);
		pid = fork();
		if (pid == 0)
		{
			ft_putendl_fd("child init", 2);
			dup2(data->pipe[0][1], 1);
			exec(argv[i], env);
		}
		else
		{
			ft_putendl_fd("parent init", 2);
			wait(NULL);
			dup2(data->pipe[0][0], 0);
			dup2(data->outfile, 1);
			exec(argv[i], env);
		}
		i++;
		if (++use_pipe > 1)
			use_pipe = 0;
	}
}

int	main(int argc, char *argv[], char *env[])
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
	pipe_cmds(&data, argv, env);
	return (0);
}
