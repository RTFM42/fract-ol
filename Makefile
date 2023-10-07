# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 10:00:38 by yushsato          #+#    #+#              #
#    Updated: 2023/10/07 20:45:49 by yushsato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I. -I./lib/libft -I./lib/minilibx_opengl
LIBMLX	= libmlx.a
LIBFT	= libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBMLX) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(INCLUDE) -framework OpenGL -framework AppKit -o $@

$(LIBMLX):
	cd lib; \
	cd minilibx_opengl; \
	make all; \
	cp $@ ../../; \
	make clean;

$(LIBFT):
	cd lib; \
	cd libft; \
	make all; \
	cp $@ ../../; \
	make fclean;

clean:
	rm -f $(OBJS) $(LIBMLX) $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
