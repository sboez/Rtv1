/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_vec_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:42:21 by sboez             #+#    #+#             */
/*   Updated: 2017/12/12 16:27:33 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vect		vec_cross(t_vect a, t_vect b)
{
	t_vect	c;

	c.x = a.y * b.z - b.y * a.z;
	c.y = a.z * b.x - b.z * a.x;
	c.z = a.x * b.y - b.x * a.y;
	return (c);
}

t_vect		vec_add(t_vect a, t_vect b)
{
	t_vect	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vect		vec_sub(t_vect a, t_vect b)
{
	t_vect	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vect		vec_prod(t_vect a, double i)
{
	t_vect	c;

	c.x = a.x * i;
	c.y = a.y * i;
	c.z = a.z * i;
	return (c);
}

t_vect		rev_vec(t_vect a)
{
	t_vect b;

	b.x = -a.x;
	b.y = -a.y;
	b.z = -a.z;
	return (b);
}
