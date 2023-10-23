/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:50:40 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/23 22:01:58 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static unsigned int	mandelbrot_color(t_complex *com, int pixel)
{
	t_complex	z;
	int			n;

	ft_bzero(&z, sizeof(t_complex));
	n = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && n < pixel / 4)
	{
		complex_mul(&z, &z);
		complex_add(&z, com);
		n++;
	}
	if (z.real * z.real + z.imag * z.imag < 4)
	{
		if (1 < n)
			return (0x0);
		return (0x00FF0000);
	}
	return (0x0 + n * 100 * pow(16, 4));
}

/**
 *
 * l = [xmin, ymin, xmax, ymax]
 *
 */

static void	make_mandelbrot(t_data *img, int pixel, double s)
{
	const double	l[] = {-2, -2, 2, 2};
	unsigned int	res;
	t_complex		p_com;
	int				p_cnt[2];

	ft_bzero(&p_com, sizeof(t_complex));
	p_cnt[0] = 0;
	while (p_cnt[0] < pixel)
	{
		p_cnt[1] = 0;
		while (p_cnt[1] < pixel)
		{
			p_com.real = l[0] / s + ((l[2] - l[0]) / pixel) * p_cnt[0] / s;
			p_com.imag = l[1] / s + ((l[3] - l[1]) / pixel) * p_cnt[1] / s;
			res = mandelbrot_color(&p_com, pixel);
			fr_mlx_pixel_put(img, p_cnt[0], p_cnt[1], res);
			p_cnt[1]++;
		}
		p_cnt[0]++;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	static double	size = 1;

	if (keycode == 4)
		size += 0.1;
	else if (keycode == 5)
		size -= 0.1;
	else
		return (0);
	ft_printf("called\n");
	make_mandelbrot(vars->img, 500, size);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img->img, 0, 0);
	return (0);
}

void	fr_mandelbrot(void)
{
	t_data		img;
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	vars.img = &img;
	make_mandelbrot(&img, 500, 1);
	mlx_put_image_to_window(vars.mlx, vars.window, img.img, 0, 0);
	mlx_hook(vars.window, 17, 1L << 0, on_window_destroy, &vars);
	mlx_key_hook(vars.window, key_hook, &vars);
	mlx_loop(vars.mlx);
	return ;
}
