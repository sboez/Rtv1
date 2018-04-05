/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:42:21 by sboez             #+#    #+#             */
/*   Updated: 2017/12/12 17:24:00 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_fnd	init_find(void)
{
	return ((t_fnd){0, 80000, 0x000000, 0, (t_vect){0, 0, 0}, NULL,
		(t_vect){0, 0, 0}, (t_vect){0, 0, 0}});
}

void	set_cam(t_vect *o, t_vect *d, t_lst *lst, t_vect pt)
{
	t_vect tmp;

	tmp = vec_add(lst->obj->upleft, vec_prod(lst->obj->idtx, pt.x));
	tmp = vec_sub(tmp, vec_prod(lst->obj->idty, pt.y));
	*o = lst->obj->pos;
	*d = mkvec(*o, tmp);
	*d = norma(*d);
}

double	set_light(t_vect *o, t_vect *d, t_fnd *find, t_lst *lst)
{
	double color_tmp;

	*o = find->pt;
	*d = mkvec(*o, lst->obj->pos);
	find->t = do_dist(*d);
	*d = norma(*d);
	find->fd = 0;
	color_tmp = find->color;
	find->color = 0x000000;
	return (color_tmp);
}
