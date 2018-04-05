/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_finder2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:42:21 by sboez             #+#    #+#             */
/*   Updated: 2017/12/12 16:27:03 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	ft_solver(double a, double b, double c)
{
	double	det;
	t_vect	bob;

	det = b * b - 4 * a * c;
	if (det < 0.0001)
		return (-1);
	bob.x = (-b + sqrt(det)) / (2 * a);
	bob.y = (-b - sqrt(det)) / (2 * a);
	bob.z = ((bob.x < bob.y && bob.x > 0) ? bob.x : bob.y);
	if (bob.z < 0)
		bob.z = 0;
	return (bob.z);
}

t_vect	ft_whisky(double t, t_vect o, t_vect d)
{
	return ((t_vect){o.x + t * d.x, o.y + t * d.y, o.z + t * d.z});
}

void	ft_copy_fnd(t_fnd a, t_fnd *b)
{
	b->fd = a.fd;
	b->t = a.t;
	b->color = a.color;
	b->norm_2 = a.norm_2;
	b->pt = a.pt;
	b->obj = a.obj;
	b->norm = a.norm;
	b->norm2 = a.norm2;
}
