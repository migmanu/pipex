# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 15:38:28 by jmigoya-          #+#    #+#              #
#    Updated: 2023/09/23 17:26:02 by jmigoya-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Werror -Wall -Wextra
HEADER = pipex.h
LIBFT = ./libft

FILES = main.c utils.c

OBJS = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.h .
	mv libft.h $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT) -lft

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
