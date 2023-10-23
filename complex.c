/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:35:35 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/19 17:47:22 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	*complex_mul(t_complex *dst, t_complex *effect)
{
	t_complex	cpy1;
	t_complex	cpy2;

	ft_memcpy(&cpy1, dst, sizeof(t_complex));
	ft_memcpy(&cpy2, effect, sizeof(t_complex));
	dst->real = cpy1.real * cpy2.real - cpy1.imag * cpy2.imag;
	dst->imag = cpy1.real * cpy2.imag + cpy2.real * cpy1.imag;
	return (dst);
}

t_complex	*complex_add(t_complex *dst, t_complex *effect)
{
	t_complex	cpy1;
	t_complex	cpy2;

	ft_memcpy(&cpy1, dst, sizeof(t_complex));
	ft_memcpy(&cpy2, effect, sizeof(t_complex));
	dst->real = cpy1.real + cpy2.real;
	dst->imag = cpy1.imag + cpy2.imag;
	return (dst);
}
