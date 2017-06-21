/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:27:17 by efedorov          #+#    #+#             */
/*   Updated: 2017/02/23 14:29:14 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	k = 0;
	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		new = malloc(i + j + 1);
		if (new == NULL)
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i] != '\0')
			new[k++] = s1[i++];
		while (s2[j] != '\0')
			new[k++] = s2[j++];
		new[k] = '\0';
		return (new);
	}
	return (NULL);
}
