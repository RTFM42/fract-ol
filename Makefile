# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 10:00:38 by yushsato          #+#    #+#              #
#    Updated: 2023/10/07 10:05:24 by yushsato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRCS	=

all: $(NAME)

$(NAME): $(SRCS)
	$(CFLAGS) -o $@ $< 

clean:
	rm -f

fclean: clean
	rm -f $(NAME)

re: fclean all
