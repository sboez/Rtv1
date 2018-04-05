/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_parse_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2018/03/02 20:19:35 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		check_buf3(char *str, char *name)
{
	int		s;

	s = ft_count_s(str);
	if (!ft_strcmp(name, "camera") && s != 9)
		ft_error(5);
	if (!ft_strcmp(name, "plan") && s != 7)
		ft_error(5);
	if (!ft_strcmp(name, "sphere") && s != 5)
		ft_error(5);
	if (!ft_strcmp(name, "cylindre") && s != 8)
		ft_error(5);
	if (!ft_strcmp(name, "cone") && s != 8)
		ft_error(5);
	if (!ft_strcmp(name, "lumiere") && s != 5)
		ft_error(5);
	return (0);
}

int		check_buf2(char *str)
{
	static int	cam = 1;
	int			i;
	char		*name;

	i = 0;
	while (!issp(str[i]))
		i++;
	name = ft_strsub(str, 0, i);
	if (!ft_strcmp(name, "camera"))
		cam--;
	if (cam < 0)
		ft_error(4);
	if (!ft_strcmp(name, "camera") || !ft_strcmp(name, "plan") ||
		!ft_strcmp(name, "sphere") || !ft_strcmp(name, "cylindre") ||
		!ft_strcmp(name, "cone") || !ft_strcmp(name, "lumiere"))
		i = check_buf3(str, name);
	free(name);
	if (i == 0)
		return (i);
	ft_error(6);
	return (-1);
}

int		check_buf(char *str)
{
	int i;

	if (issp(str[0]))
		return (-1);
	i = 0;
	while (str[i])
	{
		if (issp(str[i]) && issp(str[i + 1]))
			return (-1);
		i++;
	}
	return (check_buf2(str));
}
