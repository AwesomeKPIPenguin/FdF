# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: domelche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 18:15:36 by domelche          #+#    #+#              #
#    Updated: 2018/02/18 18:12:46 by domelche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_NAME = libft.a

LIBFT_PATH = libft/$(LIBFT_NAME)

LIBMLX_PATH = minilibx_macos

SRCS = src/*.c

OBJ = $(patsubst %.c,%.o,$(wildcard src/*.c))

HEAD = fdf.h

CFLAGS = -Wall -Wextra -Werror

FLAGS = -lmlx -framework OpenGL -framework AppKit

CC = gcc

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L $(LIBMLX_PATH) $(LIBFT_PATH) $(FLAGS)

clean:
	@/bin/rm -f src/*.o
	@$(MAKE) clean -C libft

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) fclean -C libft

re: fclean all
