/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:29:45 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/01 20:17:52 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	put_color(t_complex com, int pixel, double real, double imag)
{
	const int	clutter = 2;
	t_complex	calc;
	int			n;
	int			rgb;

	ft_bzero(&calc, sizeof(t_complex));
	n = 0;
	calc.real = real;
	calc.imag = imag;
	while (pow(com.real, 2) + pow(com.imag, 2) <= 4 && n < pixel / clutter)
	{
		complex_mul(&com, &com);
		complex_add(&com, &calc);
		n++;
	}
	rgb = 512 / (pixel / clutter) * n;
	if (rgb < 256)
		return (0x000000 + rgb * pow(16, 4));
	if (rgb >= 256 && rgb < 512)
		return (0xFF0000 + (rgb - 256) * pow(16, 2));
	return (0x000000);
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
			color = put_color(com, vars->pixel, vars->j_real, vars->j_imag);
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
		scale *= 1.1;
	if (5 == key_code)
		scale *= 0.9;
	put(vars, scale);
	return (0);
}

void	fr_julia(double real, double imag)
{
	t_vars	vars;
	t_data	img;

	vars.j_real = real;
	vars.j_imag = imag;
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
