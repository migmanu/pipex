/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:24:25 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/05 13:59:48 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H 
# define PIPEX_H

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

# define CMD_NOT_FOUND 127
# define ERROR			1
# define ARG_ERR		3
# define OPEN_ERR		4
# define PIPE_ERR		5
# define FORK_ERR		6

typedef struct s_pipex
{
	int	in_fd;
	int	out_fd;
	int	cmd_count;
}	t_pipex;

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

# ifndef FALSE
#  define FALSE false
# endif

# ifndef TRUE
#  define TRUE true
# endif

// utils.c
void	error(int err);
void	exec(char *cmd_str, char *env[]);

#endif
