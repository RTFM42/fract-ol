/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:29:45 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/27 17:05:25 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	put_color(t_complex com, int pixel)
{
	const int	clutter = 10;
	t_complex	calc;
	int			n;

	ft_bzero(&calc, sizeof(t_complex));
	n = 0;
	calc.real = -1;
	calc.imag = -1;
	while (pow(com.real, 2) + pow(com.imag, 2) <= 4 && n < pixel / clutter)
	{
		complex_mul(&com, &com);
		complex_add(&com, &calc);
		n++;
	}
	if (pow(com.real, 2) + pow(com.imag, 2) >= 4)
		return (0x00FFFFFF);
	return (0x00000000
			+ ((256 * clutter / pixel) * n * pow(16, 4))
			+ ((256 * clutter / pixel) * n));
}

static void	put(t_vars *vars, double size)
{
	t_complex	com;
	int			pos[2];
	int			color;

	pos[0] = 0;
	while (pos[0] < vars->pixel)
	{
		pos[1] = 0;
		com.real = (-2.0 + 4.0 / vars->pixel * pos[0]) / size;
		while (pos[1] < vars->pixel)
		{
			com.imag = (-2.0 + 4.0 / vars->pixel * pos[1]) / size;
			color = put_color(com, vars->pixel);
			fr_mlx_pixel_put(vars->img, pos[0], pos[1], color);
			pos[1]++;
		}
		pos[0]++;
	}
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img->img, 0, 0);
}

static int	mouse_hook(int key_code, int x, int y, t_vars *vars)
{
	static double	scale = 1;

	(void)x;
	(void)y;
	if (4 == key_code)
		scale += 0.1;
	if (5 == key_code)
		scale -= 0.1;
	put(vars, scale);
	return (0);
}

void	fr_julia(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.pixel = 500;
	vars.img = &img;
	vars.window = mlx_new_window(vars.mlx, vars.pixel, vars.pixel,
			"fractol-mandelbrot");
	img.img = mlx_new_image(vars.mlx, vars.pixel, vars.pixel);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	put(&vars, 1);
	mlx_mouse_hook(vars.window, mouse_hook, &vars);
	mlx_key_hook(vars.window, fr_exit_wind, &vars);
	mlx_hook(vars.window, 17, 1L << 0, fr_exit, 0);
	mlx_loop(vars.mlx);
	return ;
}
