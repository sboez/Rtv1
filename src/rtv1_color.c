/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:42:21 by sboez             #+#    #+#             */
/*   Updated: 2017/12/12 17:23:51 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vect	ft_decomp_color(int color)
{
	t_vect	color_dcp;

	color_dcp.x = (color & 0xFF0000) >> 16;
	color_dcp.y = (color & 0xFF00) >> 8;
	color_dcp.z = (color & 0xFF);
	return (color_dcp);
}

int		ft_color_mix(t_quad color)
{
	t_vect	a;
	t_vect	b;
	t_vect	c;
	t_vect	d;
	t_vect	fin;

	a = ft_decomp_color(color.a);
	b = ft_decomp_color(color.b);
	c = ft_decomp_color(color.c);
	d = ft_decomp_color(color.d);
	fin.x = (int)((a.x + b.x + c.x + d.x) / 4);
	fin.y = (int)((a.y + b.y + c.y + d.y) / 4);
	fin.z = (int)((a.z + b.z + c.z + d.z) / 4);
	fin.x = (fin.x > 255 ? 255 : fin.x);
	fin.y = (fin.y > 255 ? 255 : fin.y);
	fin.z = (fin.z > 255 ? 255 : fin.z);
	return ((0x010000 * fin.x) + (0x000100 * fin.y) + (0x000001 * fin.z));
}

double	ft_light(t_vect d_li, t_vect norm, t_vect norm2, int color)
{
	double	angle;
	double	angle2;
	int		r;
	int		g;
	int		b;

	angle = scal(norma(d_li), norma(norm));
	angle2 = scal(norma(d_li), norma(norm2));
	angle = (angle > angle2 ? angle : angle2);
	if (angle < 0)
		angle = 0;
	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	r = ((r * angle * 1.5) > 255 ? 255 : r * angle * 1.5);
	g = ((g * angle * 1.5) > 255 ? 255 : g * angle * 1.5);
	b = ((b * angle * 1.5) > 255 ? 255 : b * angle * 1.5);
	return ((0x010000 * r) + (0x000100 * g) + (0x000001 * b));
}
