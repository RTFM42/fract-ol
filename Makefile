# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 10:00:38 by yushsato          #+#    #+#              #
#    Updated: 2023/10/27 15:53:08 by yushsato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
SRCS	= main.c \
		  complex.c \
		  fr_hook.c \
		  fr_mandelbrot.c \
		  fr_julia.c \
		  fr_mlx.c
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I. -I./lib/libft -I./lib/minilibx_opengl
LIBMLX	= libmlx.a
LIBFT	= libft.a
PRINTF	= ftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBMLX) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $^ $(INCLUDE) -framework OpenGL -framework AppKit -o $@

$(LIBMLX):
	cd lib && cd minilibx_opengl \
		&& make all && cp $@ ../../ && make clean;

$(LIBFT):
	cd lib && cd libft \
		&& make all && cp $@ ../../ && make fclean;

$(PRINTF):
	cd lib && cd ft_printf \
		&& make all && cp $@ ../../ && make fclean;

clean:
	rm -f $(OBJS) $(LIBMLX) $(LIBFT) $(PRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all

build: all clean

norminette:
	find . -type f -and -name '*.c' | grep -v 'lib/mini' | awk '{system("norminette "$1)}'

norm: norminette

.PHONY: all clean fclean re
