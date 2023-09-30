# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 15:38:28 by jmigoya-          #+#    #+#              #
#    Updated: 2023/09/30 22:19:53 by migmanu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
LIBFT = ./libft

FILES = src/main.c src/utils.c

BONUS_FILES = bonus/main_bonus.c bonus/utils_bonus.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c

OBJS = $(FILES:.c=.o)

BONUS_OBJS = $(BONUS_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.h .
	mv libft.h $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT) -lft

bonus : $(BONUS_OBJS)
	make -C $(LIBFT)
	cp libft/libft.h .
	mv libft.h $(BONUS)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJS) -L $(LIBFT) -lft

clean :
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
