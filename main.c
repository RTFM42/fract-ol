/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:36:57 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/04 19:35:09 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define  DEBUG() ft_printf("[DEBUG] %d: %s\n", __LINE__, __func__)
#include <stdlib.h>
#include <libc.h>
#include "fractol.h"
#include "lib/libft/libft.h"

static int	is_num(char *s)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if ('0' <= *s && *s <= '9')
			;
		else
			return (0);
		s++;
	}
	return (1);
}

static int	is_double(char *s)
{
	char	**opts;
	int		ret;
	int		n;

	if (*s == '-')
		s++;
	opts = ft_split(s, '.');
	ret = 0;
	n = 0;
	if (opts[0] != NULL && is_num(opts[0]))
	{
		if (opts[1] == NULL && opts[0][0] != '0')
			ret = 1;
		else if (opts[0][0] == '0' && opts[0][1] == '\0'
				&& is_num(opts[1]) && opts[2] == NULL)
			ret = 1;
		else if (opts[0][0] != '0' && is_num(opts[1]) && opts[2] == NULL)
			ret = 1;
	}
	while (opts[n] != NULL)
		free(opts[n++]);
	free(opts);
	return (ret);
}

int	main(int argc, char **argv)
{
	double	opt1;
	double	opt2;

	if (argc == 2 && (!ft_memcmp("mandelbrot", argv[1], 11)
			|| !ft_memcmp("m", argv[1], 2)))
		fr_mandelbrot();
	else if (argc == 4 && (!ft_memcmp("julia", argv[1], 6)
			|| !ft_memcmp("j", argv[1], 2))
		&& is_double(argv[2]) && is_double(argv[3]))
	{
		opt1 = ft_atod(argv[2]);
		opt2 = ft_atod(argv[3]);
		fr_julia(opt1, opt2);
	}
	else
	{
		ft_printf("Illigal Option\nUsage:\n\t%s [mandelbrot | m]\n", argv[0]);
		ft_printf("\t%s [julia | j] (number) (number)\n", argv[0]);
		return (1);
	}
	return (0);
}
