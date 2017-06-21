/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:04:05 by efedorov          #+#    #+#             */
/*   Updated: 2017/02/24 16:41:03 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init(t_map *map)
{
	if (!(map->mlx = mlx_init()))
		return (1);
	map->win = mlx_new_window(map->mlx, 1920, 1080, "fdf");
	map->red = 255;
	map->green = 50;
	map->blue = 50;
	map->i = 45;
	map->z = 3;
	map->a = 0.4;
	return (0);
}

int		loop_draw(t_map *map)
{
	ft_draw(map);
	return (0);
}

void	ft_fill(t_map *map, char **tmp, int x, int y)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		map->map[y][x] = ft_atoi(tmp[i]);
		x++;
		i++;
	}
	map->length = i;
}

void	put_pxl(t_map *map, int x, int y)
{
	if (((x > 0) && (y > 0)) && ((x < 1920) && (y < 1080)))
	{
		map->tmp[(x * 4) + (y * 1920 * 4)] = map->blue;
		map->tmp[(x * 4) + (y * 1920 * 4) + 1] = map->green;
		map->tmp[(x * 4) + (y * 1920 * 4) + 2] = map->red;
	}
}
