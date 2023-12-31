/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:30:50 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/27 15:48:15 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fr_mlx_pixel_put(t_data *img, int x, int y, unsigned int color)
{
	char			*dst;

	dst = img->addr + (x * (img->bits_per_pixel / 8) + y * img->line_length);
	*(unsigned int *)dst = color;
}
