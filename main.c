/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:36:57 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/07 20:51:54 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

t_complex	*complex_add(t_complex self, t_complex other)
{
	t_complex	*res;

	res = ft_calloc(1, sizeof(t_complex));
	res->real = self.real + other.real;
	res->imag = self.imag + other.imag;
	return (res);
}

int	main(const int argc, const char **argv)
{
	mlx_init();
}
