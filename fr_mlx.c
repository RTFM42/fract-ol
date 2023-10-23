/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:30:50 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/23 19:56:23 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fr_mlx_pixel_put(t_data *img, int x, int y, unsigned int color)
{
	char			*dst;

	dst = img->addr + (x * (img->bits_per_pixel / 8) + y * img->line_length);
	*(unsigned int *)dst = color;
}

int	on_window_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	exit(0);
}
