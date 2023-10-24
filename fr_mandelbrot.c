/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:50:40 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/24 22:47:10 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

#define	DEBUG() ft_printf("%d, %s\n", __LINE__, __func__)
static int	put_mandelbrot_color(t_complex com, int pixel)
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

static void	put_mandelbrot(t_vars *vars, double size)
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
			color = put_mandelbrot_color(com, vars->pixel);
			fr_mlx_pixel_put(vars->img, pos[0], pos[1], color);
			pos[1]++;
		}
		pos[0]++;
	}
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img->img, 0, 0);
}

static int	hook(int key_code, int x ,int y, t_vars *vars)
{
	static int	scale = 1;
	(void)x;
	(void)y;
	if (4 == key_code)
		scale += 0.1;
	if (5 == key_code)
		scale -= 0.1;
	put_mandelbrot(vars, scale);
	return (0);
}

void	fr_mandelbrot(void)
{
	t_vars		vars;
	t_data		img;

	vars.mlx = mlx_init();
	vars.pixel = 500;
	vars.img = &img;
	vars.window = mlx_new_window(vars.mlx, vars.pixel, vars.pixel, "fractol-mandelbrot");
	img.img = mlx_new_image(vars.mlx, vars.pixel, vars.pixel);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	put_mandelbrot(&vars, 1);
	mlx_mouse_hook(vars.window, hook, &vars);
	mlx_loop(vars.mlx);
	return ;
}
