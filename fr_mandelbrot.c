/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:50:40 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/24 19:14:01 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	put_mandelbrot_color(t_complex com, int pixel)
{
	const int	clutter = 12;
	t_complex	calc;
	int			n;

	ft_bzero(&calc, sizeof(t_complex));
	n = 0;
	while (pow(calc.real, 2) + pow(calc.imag, 2) <= 4 && n < pixel / clutter)
	{
		complex_mul(&calc, &calc);
		complex_add(&calc, &com);
		n++;
	}
	if (pow(calc.real, 2) + pow(calc.imag, 2) <= 4)
		return (0x00FFFFFF);
	return (0x00000000 + ((256 * clutter / pixel) * n * pow(16, 4)));
}

void	put_mandelbrot(t_vars *vars, t_data *img, int pixel, double size)
{
	t_complex	com;
	int			pos[2];
	int			color;

	pos[0] = 0;
	while (pos[0] < pixel)
	{
		pos[1] = 0;
		com.real = (-2.0 + 4.0 / pixel * pos[0]) / size;
		while (pos[1] < pixel)
		{
			com.imag = (-2.0 + 4.0 / pixel * pos[1]) / size;
			ft_printf("%d %d\n", com.real, com.imag);
			color = put_mandelbrot_color(com, pixel);
			fr_mlx_pixel_put(img, pos[0], pos[1], color);
			pos[1]++;
		}
		pos[0]++;
	}
	mlx_put_image_to_window(vars->mlx, vars->window, img->img, 0, 0);
}

void	fr_mandelbrot(void)
{
	const int	pixel = 500;
	t_vars		vars;
	t_data		img;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, pixel, pixel, "fractol-mandelbrot");
	img.img = mlx_new_image(vars.mlx, pixel, pixel);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	put_mandelbrot(&vars, &img, pixel, 1);
	mlx_loop(vars.mlx);
	return ;
}
