/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* fr_mandelbrot.c                                    :+:    :+: :+:    :+: :+:    :+: :+:    :+: :+:         */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:29:40 by yushsato          #+#    #+#             */
/* Updated: 2023/10/23 18:48:07 by yukun         #########  ########   ########   ###    ### ##########.io    */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	on_window_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	exit(0);
}

// static void	make_mandelbrot(t_data *img, int size_per, int width, int height)
// {
// 	const double	size = 4 * (100 / (double)size_per);
// 	int				pixel;
// 	int				count[3];
// 	double			pos[2];
// 	t_complex		c[2];
// 
// 	count[0] = -1;
// 	pixel = height;
// 	if (width < height)
// 		pixel = width;
// 	while (count[0]++ < width - 1)
// 	{
// 		count[1] = -1;
// 		while (count[1]++ < height - 1)
// 		{
// 			pos[0] = count[0] * size / pixel - size / 2;
// 			pos[1] = count[1] * size / pixel - size / 2;
// 			ft_bzero(&c, sizeof(t_complex));
// 			count[2] = -1;
// 			while (count[2]++ < 80)
// 			{
// 				c[1].real = pow(c[0].real, 2) - pow(c[0].imag, 2) + pos[0];
// 				c[1].imag = c[0].real * c[0].imag * 2 + pos[1];
// 				ft_memcpy(&c[0], &c[1], sizeof(t_complex));
// 				if (c[0].real * c[0].real + c[0].imag * c[0].imag > 4)
// 					fr_mlx_pixel_put(img, count[0], count[1], count[2]);
// 			}
// 		}
// 	}
// }

static int	is_mandelbrot(t_complex *com)
{
	t_complex	z;
	int			n;

	ft_bzero(&z, sizeof(t_complex));
	n = 0;
	while (n++ < 20)
	{
		if (z.real * z.real + z.imag * z.imag > 4)
			return (n);
		complex_mul(&z, &z);
		complex_add(&z, com);
	}
	return (0);
}

//limits = [xmin, ymin, xmax, ymax]

static void	make_mandelbrot(t_data *img, int width, int height)
{
	t_complex		p_com;
	int				p_cnt[2];
	int				res;
	int				pixel;
	const double	limits[] = {-2, -2, 2, 2};

	ft_bzero(&p_com, sizeof(t_complex));
	p_cnt[0] = 0;
	pixel = height;
	if (width < height)
		pixel = width;
	while (p_cnt[0] < width)
	{
		p_cnt[1] = 0;
		while(p_cnt[1] < height)
		{
			p_com.real = limits[0] + ((limits[2] - limits[0]) / pixel) * p_cnt[0];
			p_com.imag = limits[1] + ((limits[3] - limits[1]) / pixel) * p_cnt[1];
			res = is_mandelbrot(&p_com);
			if (res)
				fr_mlx_pixel_put(img, p_cnt[0], p_cnt[1], res);
			p_cnt[1]++;
		}
		p_cnt[0]++;
	}
}

void	fr_mandelbrot(void)
{
	t_data		img;
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 600, 400, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	make_mandelbrot(&img, 600, 400);
	mlx_put_image_to_window(vars.mlx, vars.window, img.img, 0, 0);
	mlx_hook(vars.window, 17, 1L << 0, on_window_destroy, &vars);
	mlx_loop(vars.mlx);
	return ;
}
