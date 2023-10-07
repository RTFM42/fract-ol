# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 10:00:38 by yushsato          #+#    #+#              #
#    Updated: 2023/10/07 18:52:43 by yushsato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
LIB_DIR	= lib
LIBMLX	= libmlx.dylib
LIBFT	= libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBMLX) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBMLX):
	@cd $(LIB_DIR)
	@cd minilibx_mms
	@make all
	@cp $< ../../
	@make clean

$(LIBFT):
	@cd $(LIB_DIR)
	@cd libft
	@make all
	@cp $< ../../
	@make fclean

clean:
	rm -f $(OBJS) $(LIBMLX) $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
