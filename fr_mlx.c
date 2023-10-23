/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:30:50 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/20 19:55:18 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fr_mlx_pixel_put(t_data *img, int x, int y, unsigned int color)
{
	char		*dst;
	unsigned	rgb;

	dst = img->addr + (x * (img->bits_per_pixel / 8) + y * img->line_length);
	if (color < 80)
		rgb = 0x00000000
			+ (255 * color / 80 * 16 * 16 * 16 * 16)
			+ (255 * 16 * 16)
			+ 255;
	else
		rgb = 0x00000000
			+ (255 * color / 80 * 16 * 16 * 16 * 16)
			+ (255 * 16 * 16)
			+ 0;
	*(unsigned int *)dst = rgb;
}
