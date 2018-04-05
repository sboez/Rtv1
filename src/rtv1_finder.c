/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:42:21 by sboez             #+#    #+#             */
/*   Updated: 2018/03/02 19:43:39 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_plan(t_vect o, t_vect d, t_obj *plan, t_fnd *find)
{
	double	t;

	t = -((scal(plan->n, o) - scal(plan->n, plan->pt)) / (scal(plan->n, d)));
	if (t > 0.001 && ((find->fd == 0 && t < find->t) ||
		(find->fd == 1 && t < find->t)))
	{
		find->fd = 1;
		find->norm_2 = 1;
		find->t = t;
		find->color = plan->color;
		find->pt = ft_whisky(find->t, o, d);
		find->obj = plan;
		find->norm = norma(plan->n);
		find->norm2 = norma(rev_vec(plan->n));
	}
}

void	ft_blob(t_vect o, t_vect d, t_obj *sphere, t_fnd *find)
{
	t_vect	a;
	double	t;

	a.x = pow(d.x, 2) + pow(d.y, 2) + pow(d.z, 2);
	a.y = 2 * (d.x * (o.x - sphere->ctr.x) + d.y * (o.y - sphere->ctr.y)
	+ d.z * (o.z - sphere->ctr.z));
	a.z = (pow(o.x - sphere->ctr.x, 2) + pow(o.y - sphere->ctr.y, 2)
	+ pow(o.z - sphere->ctr.z, 2)) - pow(sphere->ray, 2);
	t = ft_solver(a.x, a.y, a.z);
	if (t > 0.001 && ((find->fd == 0 && t < find->t) ||
		(find->fd == 1 && t < find->t)))
	{
		ft_copy_fnd((t_fnd){1, t, sphere->color, 0, ft_whisky(t, o, d),
			sphere, norma(mkvec(sphere->ctr, ft_whisky(t, o, d))),
			rev_vec(norma(mkvec(sphere->ctr, ft_whisky(t, o, d))))}, find);
	}
}

void	ft_ice_cone(t_vect o, t_vect d, t_obj *cne, t_fnd *find)
{
	double	ag;
	t_tvec	t3;
	t_tvec	cylin;
	double	t;

	ag = cne->angle * (PI / 180);
	t3.a = vec_sub(o, cne->ctr);
	t3.b = vec_sub(d, vec_prod(cne->n, scal(d, cne->n)));
	t3.c = vec_sub(t3.a, vec_prod(cne->n, scal(t3.a, cne->n)));
	t = ft_solver(pow(cos(ag), 2.) * scal(t3.b, t3.b) - pow(sin(ag), 2.) *
	pow(scal(d, cne->n), 2.), 2. * pow(cos(ag), 2.) * scal(t3.b, t3.c) - 2.
	* pow(sin(ag), 2.) * scal(d, cne->n) * scal(t3.a, cne->n), pow(cos(ag),
	2.) * scal(t3.c, t3.c) - pow(sin(ag), 2.) * pow(scal(t3.a, cne->n), 2.));
	if (t > 0.001 && ((find->fd == 0 && t < find->t) ||
		(find->fd == 1 && t < find->t)))
	{
		cylin.a = ft_whisky(t, o, d);
		cylin.b = vec_sub(cylin.a, cne->ctr);
		cylin.c = vec_prod(cne->n, scal(norma(cylin.b), norma(cne->n)));
		cylin.c = vec_cross(cylin.b, vec_sub(cylin.b, cylin.c));
		cylin.c = vec_cross(cylin.c, cylin.b);
		ft_copy_fnd((t_fnd){1, t, cne->color, 0, ft_whisky(t, o, d),
			cne, cylin.c, rev_vec(cylin.c)}, find);
	}
}

void	ft_cylinder(t_vect o, t_vect d, t_obj *cld, t_fnd *find)
{
	t_vect	a;
	t_tvec	tmp;
	t_vect	norm;
	t_tvec	cylin;
	double	t;

	tmp.a = vec_sub(o, cld->ctr);
	tmp.b = vec_sub(d, vec_prod(cld->n, scal(d, cld->n)));
	a.x = scal(tmp.b, tmp.b);
	tmp.c = vec_sub(tmp.a, vec_prod(cld->n, scal(tmp.a, cld->n)));
	a.y = 2 * scal(tmp.b, tmp.c);
	a.z = scal(tmp.c, tmp.c) - pow(cld->ray, 2.);
	t = ft_solver(a.x, a.y, a.z);
	if (t > 0.0001 && ((find->fd == 0 && t < find->t) ||
		(find->fd == 1 && t < find->t)))
	{
		cylin.a = ft_whisky(t, o, d);
		cylin.b = vec_sub(cylin.a, cld->ctr);
		cylin.c = vec_prod(cld->n, scal(cylin.b, cld->n));
		norm = vec_sub(cylin.b, cylin.c);
		norm = norma(norm);
		ft_copy_fnd((t_fnd){1, t, cld->color, 0, ft_whisky(t, o, d),
			cld, norm, rev_vec(norm)}, find);
	}
}
