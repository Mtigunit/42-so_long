# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 17:59:12 by mtigunit          #+#    #+#              #
#    Updated: 2023/02/07 15:36:53 by mtigunit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LINKING	= -lmlx -framework OpenGL -framework AppKit
NAME	= so_long
SRCS	= check_map.c draw_map.c moves.c moves2.c utils.c backtracking.c so_long.c enemy.c
LIBFT	= ./libft/libft.a
OBJS	= check_map.o draw_map.o moves.o moves2.o utils.o backtracking.o so_long.o enemy.o

all: $(NAME)

$(LIBFT):
	$(MAKE) --silent -C ./libft

$(NAME): $(SRCS) $(LIBFT) so_long.h
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) $(LINKING)

clean:
	$(MAKE) --silent clean -C ./libft

fclean: clean
	$(MAKE) --silent fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
