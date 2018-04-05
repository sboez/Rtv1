/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_vec_calc4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:42:21 by sboez             #+#    #+#             */
/*   Updated: 2017/12/12 16:28:15 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vect	vec_div(t_vect a, double i)
{
	t_vect	c;

	c.x = a.x / i;
	c.y = a.y / i;
	c.z = a.z / i;
	return (c);
}

t_vect	vec_proj(t_vect u, t_vect v)
{
	t_vect	proj;
	double	dot;

	dot = scal(u, v) / scal(v, v);
	proj = vec_prod(v, dot);
	return (proj);
}

double	vec_coss(t_vect u, t_vect v)
{
	return (scal(norma(u), norma(v)));
}
