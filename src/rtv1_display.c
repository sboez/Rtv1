/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:42:21 by sboez             #+#    #+#             */
/*   Updated: 2018/03/02 20:13:19 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_hardstyle_loop(t_env *e, t_lst *lst)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y)
		{
			ft_ray_of_deathmetal3(e, x, y, lst);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_ray_of_deathmetal3(t_env *e, int x, int y, t_lst *lst)
{
	t_quad	color;
	int		color_tmp;

	color.a = ft_ray_of_deathmetal(x - 0.25, y - 0.25, lst);
	color.b = ft_ray_of_deathmetal(x - 0.25, y + 0.25, lst);
	color.c = ft_ray_of_deathmetal(x + 0.25, y - 0.25, lst);
	color.d = ft_ray_of_deathmetal(x + 0.25, y + 0.25, lst);
	color_tmp = ft_color_mix(color);
	ft_pixies(e, x, y, color_tmp);
}

int		ft_ray_of_deathmetal2(t_lst *lst, t_fnd find)
{
	t_lst	*tmp2;
	int		color_tmp;
	t_vect	o;
	t_vect	d;

	tmp2 = lst;
	while (tmp2)
	{
		if (tmp2->name == LUMIERE)
			color_tmp = set_light(&o, &d, &find, tmp2);
		if (tmp2->find_obj && find.obj != tmp2->obj)
			tmp2->find_obj(o, d, tmp2->obj, &find);
		tmp2 = tmp2->next;
	}
	if (find.fd == 0 && find.t > 0)
	{
		if (find.norm_2 == 1)
			color_tmp = ft_light(d, find.norm, find.norm2, color_tmp);
		else
			color_tmp = ft_light(d, find.norm, find.norm, color_tmp);
		return (color_tmp);
	}
	return (0x000000);
}

int		ft_ray_of_deathmetal(double x, double y, t_lst *lst)
{
	t_vect	o;
	t_vect	d;
	t_lst	*tmp2;
	t_fnd	find;

	find = init_find();
	tmp2 = lst;
	while (tmp2)
	{
		if (tmp2->name == CAMERA)
			set_cam(&o, &d, tmp2, (t_vect){x, y, 0});
		if (tmp2->find_obj)
			tmp2->find_obj(o, d, tmp2->obj, &find);
		tmp2 = tmp2->next;
	}
	if (find.fd == 1)
		return (ft_ray_of_deathmetal2(lst, find));
	else
		return (0x000000);
}
