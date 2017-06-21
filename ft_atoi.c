/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:47:07 by efedorov          #+#    #+#             */
/*   Updated: 2017/02/23 14:26:04 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_atoi(char *num)
{
	int sign;
	int res;
	int i;

	i = 0;
	sign = 0;
	res = 0;
	while (num[i] == '\v' || num[i] == '\t' || num[i] == '\r' || num[i] == '\f'
		|| num[i] == '\n' || num[i] == ' ')
		i++;
	if (num[i] == '-')
		sign = 1;
	if (num[i] == '+' || num[i] == '-')
		i++;
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = res * 10 + num[i] - 48;
		i++;
	}
	if (sign == 1)
		return (-res);
	else
		return (res);
}
