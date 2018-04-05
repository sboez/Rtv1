/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:42:21 by sboez             #+#    #+#             */
/*   Updated: 2018/03/02 20:12:04 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		ft_error(int i)
{
	if (i == 1)
		ft_putendl(C_ROUGE "USAGE : ./rtv1 {scene}" FIN);
	if (i == 2)
		ft_putendl(C_ROUGE "FILE ERROR" FIN);
	if (i == 3)
		ft_putendl(C_ROUGE "MEMORY ERROR" FIN);
	if (i == 4)
		ft_putendl(C_ROUGE "ONLY ONE CAMERA IN THE FILE PLEASE" FIN);
	if (i == 5)
		ft_putendl(C_ROUGE "OBJECT WITH A BAD NUMBER OF PARAMETERS" FIN);
	if (i == 6)
		ft_putendl(C_ROUGE "OBJECT WITH A BAD NAME" FIN);
	if (i == 9)
		ft_putendl(C_ROUGE "THERE ARE A ERROR BUT I DON'T KNOW WHY" FIN);
	exit(-1);
	return (-1);
}

int		ft_red_cross(void)
{
	exit(0);
}

int		ft_key(int keycode)
{
	if (keycode == EXIT)
		exit(0);
	return (0);
}

int		check_main(t_lst *lst)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putendl("Erreur Malloc -> t_env");
		exit(1);
	}
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "rtv1");
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_hardstyle_loop(e, lst);
	mlx_hook(e->win, 17, (1L << 17), ft_red_cross, NULL);
	mlx_hook(e->win, 2, 3, ft_key, 0);
	mlx_loop(e->mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_lst	*lst;

	lst = NULL;
	if (argc == 2)
	{
		if (!(lst = file_extract(argv[1])))
		{
			ft_error(9);
			return (-1);
		}
		else
			check_main(lst);
	}
	else
		ft_error(1);
	return (0);
}
