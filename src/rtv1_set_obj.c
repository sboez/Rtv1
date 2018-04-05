/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_set_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2018/03/02 20:01:10 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	set_obj11(t_obj *obj)
{
	obj->view = norma(obj->view);
	obj->upleft = vec_add(obj->pos, vec_sub(vec_add(vec_prod(obj->view,
		obj->p_dist), vec_prod(do_vec(0, 1, 0), obj->p_height / 2.0)),
	vec_prod(do_vec(1, 0, 0), obj->p_width / 2.0)));
	obj->idtx = vec_prod(do_vec(1, 0, 0), obj->p_width / (double)WIN_X);
	obj->idty = vec_prod(do_vec(0, 1, 0), obj->p_height / (double)WIN_Y);
}

void	set_obj1(int name, char *str, int i, t_obj *obj)
{
	int		cp;

	cp = i;
	if (name == CAMERA)
	{
		obj->pos = (t_vect){get_next_nbr(str, &cp, 10), get_next_nbr(str,
			&cp, 10), get_next_nbr(str, &cp, 10)};
		obj->view = (t_vect){get_next_nbr(str, &cp, 10), get_next_nbr(str,
			&cp, 10), get_next_nbr(str, &cp, 10)};
		obj->p_dist = get_next_nbr(str, &cp, 10);
		obj->p_width = get_next_nbr(str, &cp, 10);
		obj->p_height = get_next_nbr(str, &cp, 10);
		set_obj11(obj);
	}
	else if (name == SPHERE)
	{
		obj->ctr = (t_vect){get_next_nbr(str, &cp, 10), get_next_nbr(str,
			&cp, 10), get_next_nbr(str, &cp, 10)};
		obj->ray = get_next_nbr(str, &cp, 10);
		obj->color = get_next_nbr(str, &cp, 16);
	}
}

void	set_obj2(int name, char *str, int i, t_obj *obj)
{
	int		cp;

	cp = i;
	if (name == PLAN)
	{
		obj->pt = (t_vect){get_next_nbr(str, &cp, 10), get_next_nbr(str,
			&cp, 10), get_next_nbr(str, &cp, 10)};
		obj->n = (t_vect){get_next_nbr(str, &cp, 10), get_next_nbr(str,
			&cp, 10), get_next_nbr(str, &cp, 10)};
		obj->n = norma(obj->n);
		obj->color = get_next_nbr(str, &cp, 16);
	}
	else if (name == CYLINDRE)
	{
		obj->ctr = (t_vect){get_next_nbr(str, &cp, 10), get_next_nbr(str,
			&cp, 10), get_next_nbr(str, &cp, 10)};
		obj->n = (t_vect){get_next_nbr(str, &cp, 10), get_next_nbr(str,
			&cp, 10), get_next_nbr(str, &cp, 10)};
		obj->n = norma(obj->n);
		obj->ray = get_next_nbr(str, &cp, 10);
		obj->color = get_next_nbr(str, &cp, 16);
	}
}

void	set_obj3(int name, char *str, int i, t_obj *obj)
{
	int		cp;

	cp = i;
	if (name == CONE)
	{
		obj->ctr = (t_vect){get_next_nbr(str, &cp, 10), get_next_nbr(str,
			&cp, 10), get_next_nbr(str, &cp, 10)};
		obj->n = (t_vect){get_next_nbr(str, &cp, 10), get_next_nbr(str,
			&cp, 10), get_next_nbr(str, &cp, 10)};
		obj->n = norma(obj->n);
		obj->angle = get_next_nbr(str, &cp, 10);
		obj->color = get_next_nbr(str, &cp, 16);
	}
	else if (name == LUMIERE)
	{
		obj->pos = (t_vect){get_next_nbr(str, &cp, 10), get_next_nbr(str,
			&cp, 10), get_next_nbr(str, &cp, 10)};
		obj->its = get_next_nbr(str, &cp, 10);
		obj->color = get_next_nbr(str, &cp, 16);
	}
}

t_obj	*make_obj(int name, char *str, int i)
{
	t_obj	*obj;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (name == CAMERA || name == SPHERE)
		set_obj1(name, str, i, obj);
	else if (name == PLAN || name == CYLINDRE)
		set_obj2(name, str, i, obj);
	else if (name == CONE || name == LUMIERE)
		set_obj3(name, str, i, obj);
	return (obj);
}
