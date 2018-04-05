/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_usefull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/12/12 16:27:29 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static int	ft_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)));
}

int			ft_atoi_base(char *str, int base)
{
	int		value;
	int		sign;

	value = 0;
	if (base <= 1 || base > 36)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, base))
	{
		if (*str - 'A' >= 0)
			value = value * base + (*str - 'A' + 10);
		else
			value = value * base + (*str - '0');
		str++;
	}
	return (value * sign);
}

int			issp(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

int			ft_count_s(char *str)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (str[i])
	{
		if (issp(str[i]))
			s++;
		i++;
	}
	return (s);
}

int			get_next_nbr(char *str, int *i, int base)
{
	*i = *i + 1;
	while (!(!issp(str[*i]) && issp(str[*i - 1])))
		*i = *i + 1;
	if (base == 16)
		*i = *i + 2;
	return (ft_atoi_base(&str[*i], base));
}
