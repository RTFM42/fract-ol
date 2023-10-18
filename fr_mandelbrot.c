/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:29:40 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/19 02:53:07 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_window_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	exit(0);
}

static void	calc_mandelbrot(t_data *img, int size_per, int width, int height)
{
	const double	size = 4 * (100 / (double)size_per);
	int				count[3];
	double			pos[2];
	t_complex		c[2];

	count[0] = -1;
	while (count[0]++ < width - 1)
	{
		pos[0] = count[0] * size / width - size / 1.5;
		count[1] = -1;
		while (count[1]++ < height - 1)
		{
			pos[1] = count[1] * size / height - size / 2;
			ft_bzero(&c, sizeof(t_complex));
			count[2] = -1;
			while (count[2]++ < 200)
			{
				c[1].real = pow(c[0].real, 2) - pow(c[0].imag, 2) + pos[0];
				c[1].imag = c[0].real * c[0].imag * 2 + pos[1];
				ft_memcpy(&c[0], &c[1], sizeof(t_complex));
				if (c[0].real * c[0].real + c[0].imag * c[0].imag > 4)
					fr_mlx_pixel_put(img, count[0], count[1], 0x00FF0000);
			}
		}
	}
}

void	fr_mandelbrot(void)
{
	t_data		img;
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 1080, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	calc_mandelbrot(&img, 200, 1080, 1080);
	mlx_put_image_to_window(vars.mlx, vars.window, img.img, 0, 0);
	mlx_hook(vars.window, 17, 1L << 0, on_window_destroy, &vars);
	mlx_loop(vars.mlx);
	return ;
}
