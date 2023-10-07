/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:52:42 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/07 21:39:35 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "lib/libft/libft.h"

t_complex	*complex_add(t_complex self, t_complex other)
{
	t_complex	*res;

	res = ft_calloc(1, sizeof(t_complex));
	res->real = self.real + other.real;
	res->imag = self.imag + other.imag;
	return (res);
}

t_complex	*complex_sub(t_complex self, t_complex other)
{
	t_complex	*res;

	res = ft_calloc(1, sizeof(t_complex));
	res->real = self.real - other.real;
	res->imag = self.imag - other.imag;
	return (res);
}

t_complex	*complex_mul(t_complex self, t_complex other)
{
	t_complex	*res;

	res = ft_calloc(1, sizeof(t_complex));
	res->real = self.real * other.real - self.imag * other.imag;
	res->imag = self.real * other.imag + other.real * self.imag;
	return (res);
}

t_complex	*complex_div(t_complex self, t_complex other)
{
	t_complex	*res;
	size_t		div;

	res = ft_calloc(1, sizeof(t_complex));
	div = (other.real * other.real + other.imag * other.imag);
	res->real = (self.real * other.real + self.imag * other.imag) / div;
	res->imag = (self.imag * other.real + self.real * other.imag) / div;
	return (res);
}
