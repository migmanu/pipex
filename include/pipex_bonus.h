/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:24:25 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/10/03 16:01:53 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define HERE_DOC "/tmp/.here_doc_file"

# define CMD_NOT_FOUND 127
# define ERROR			1
# define ARG_ERR		3
# define OPEN_ERR		4
# define PIPE_ERR		5
# define FORK_ERR		6

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
	int	pipe[2][2];
	int	here_doc;
	int	argc;
}	t_pipex;

# ifndef FALSE
#  define FALSE false
# endif

# ifndef TRUE
#  define TRUE true
# endif

// pipex_bonus.c
char	*get_path(char *cmd, char *env[]);
int		check_args(int argc, char *argv[]);
int		get_next_line(char **line);

// here_doc.c
int	do_here_doc(t_pipex *data, int argc, char *argv[]);

#endif
