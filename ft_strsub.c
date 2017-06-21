/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:16:38 by efedorov          #+#    #+#             */
/*   Updated: 2017/02/23 14:29:38 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (s)
	{
		new = malloc(len + 1);
		if (!new)
			return (NULL);
		i = 0;
		while (len)
		{
			new[i] = s[start + i];
			i++;
			len--;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
