/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:43:07 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/27 15:48:24 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/minilibx_opengl/mlx.h"
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <math.h>

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*window;
	int		pixel;
	int		size;
	t_data	*img;
}	t_vars;

t_complex	*complex_mul(t_complex *dst, t_complex *effect);
t_complex	*complex_add(t_complex *dst, t_complex *effect);
void		fr_mlx_pixel_put(t_data *img, int x, int y, unsigned int color);
void		fr_mandelbrot(void);
void		fr_julia(void);
int			fr_exit_wind(int keycode, t_vars *vars);
int			fr_exit(int e_code);

#endif
