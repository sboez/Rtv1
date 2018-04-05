/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_vec_calc3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:42:21 by sboez             #+#    #+#             */
/*   Updated: 2017/12/12 16:27:40 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	do_dist_sqrd(t_vect a, t_vect b)
{
	return (pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}

double	do_dist(t_vect a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

void	ft_pixies(t_env *e, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < WIN_Y && x < WIN_X)
	{
		e->data[(y * e->sizeline) + ((e->bpp / 8) * x) + 2] = r;
		e->data[(y * e->sizeline) + ((e->bpp / 8) * x) + 1] = g;
		e->data[(y * e->sizeline) + ((e->bpp / 8) * x)] = b;
	}
}

double	ft_pow(double a, double b)
{
	double	tmp;

	tmp = a;
	while (b > 1)
	{
		a = a * tmp;
		b--;
	}
	return (a);
}

double	ft_sqrt(double a)
{
	double	i;

	i = 1;
	while (i * i < a)
		i++;
	if (i * i == a)
		return (i);
	else
		return (0);
}
