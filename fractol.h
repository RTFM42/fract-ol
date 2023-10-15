/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:43:07 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/15 22:28:58 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/minilibx_opengl/mlx.h"
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

typedef struct s_complex
{
	int	real;
	int	imag;
}	t_complex;

t_complex	*complex_add(t_complex self, t_complex other);
t_complex	*complex_sub(t_complex self, t_complex other);
t_complex	*complex_mul(t_complex self, t_complex other);
t_complex	*complex_div(t_complex self, t_complex other);
void		*fr_mandelbrot();
void		*fr_julia();

#endif
