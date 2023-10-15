/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:36:57 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/15 22:33:10 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "lib/libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && (ft_memcmp("mandelbrot", argv[1], 11)
			|| ft_memcmp("m", argv[1], 2)))
		fr_mandelbrot();
	else if (argc == 2 && (ft_memcmp("julia", argv[1], 6)
			|| ft_memcmp("j", argv[1], 2)))
		fr_julia();
	else
	{
		ft_printf("Illigal Option");
		ft_printf("Usage:");
		ft_printf("\t%s [mandelbrot | julia | m | j]", argv[0]);
		return (1);
	}
	return (0);
}
