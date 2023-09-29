/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:24:25 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/29 16:15:14 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int	infile;
	int	outfile;
	int	pipe_read;
	int	pipe_write;
	int	control;
}	t_pipex;

# ifndef FALSE
#  define FALSE false
# endif

# ifndef TRUE
#  define TRUE true
# endif

// utils.c
void	handle_error(void);
int		exec(char *cmd_str, char *env[]);
int		open_file(char *file, int file_type);
char	*get_path(char *cmd, char *env[]);
void	pipe_cmds(char *cmd, char **env);

#endif
