/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:36:57 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/01 21:00:04 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define  DEBUG() ft_printf("[DEBUG] %d: %s\n", __LINE__, __func__)
#include <stdlib.h>
#include <libc.h>
#include "fractol.h"
#include "lib/libft/libft.h"

int	main(int argc, char **argv)
{
	double	opt1;
	double	opt2;

	if (argc == 2 && (!ft_memcmp("mandelbrot", argv[1], 11)
			|| !ft_memcmp("m", argv[1], 2)))
		fr_mandelbrot();
	else if (argc == 4 && (!ft_memcmp("julia", argv[1], 6)
			|| !ft_memcmp("j", argv[1], 2)))
	{
		opt1 = ft_atod(argv[2]);
		opt2 = ft_atod(argv[3]);
		fr_julia(opt1, opt2);
	}
	else
	{
		ft_printf("Illigal Option\nUsage:\n\t%s [mandelbrot | m]\n
				\t%s [julia | j] (number) (number)\n", argv[0], argv[0]);
		return (1);
	}
	return (0);
}
