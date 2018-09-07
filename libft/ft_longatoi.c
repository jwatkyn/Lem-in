/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longatoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:26:18 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/22 07:43:01 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_longatoi(const char *str)
{
	long int	res;
	int			i;
	long int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\n' ||
			str[i] == '\t' ||
			str[i] == '\r' ||
			str[i] == '\v' ||
			str[i] == '\f' ||
			str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
