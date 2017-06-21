/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:15:09 by efedorov          #+#    #+#             */
/*   Updated: 2017/02/23 13:47:55 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_img(t_map *map)
{
	int		size_line;
	int		bits_p_p;
	int		endian;

	map->img = mlx_new_image(map->mlx, 1920, 1080);
	map->tmp = mlx_get_data_addr(map->img, &bits_p_p, &size_line, &endian);
}

void	destroy_img(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_destroy_image(map->mlx, map->img);
}

void	draw_lines(t_map *map)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	vect;

	x1 = map->x[0];
	y1 = map->y[0];
	x2 = map->x[1] - map->x[0];
	y2 = map->y[1] - map->y[0];
	vect = sqrt(x2 * x2 + y2 * y2);
	x2 /= vect;
	y2 /= vect;
	while (vect >= 0)
	{
		put_pxl(map, x1, y1);
		x1 += x2;
		y1 += y2;
		vect--;
	}
}

void	ft_transformation(t_map *map, int x, int y, int i)
{
	int		x_c;
	int		y_c;

	x_c = x - map->length / 2;
	y_c = y - map->width / 2;
	map->x[0] = cos(map->a) * x_c * map->i - sin(map->a) * y_c * map->i;
	map->y[0] = sin(map->a) * x_c * map->i + cos(map->a) * \
		y_c * map->i - map->map[y][x] * map->z;
	if (i == 1)
	{
		map->x[1] = cos(map->a) * ++x_c * map->i - sin(map->a) * y_c * map->i;
		map->y[1] = sin(map->a) * x_c * map->i + cos(map->a) * y_c * \
			map->i - map->map[y][x + 1] * map->z;
	}
	else
	{
		map->x[1] = cos(map->a) * x_c * map->i - sin(map->a) * ++y_c * \
			map->i;
		map->y[1] = sin(map->a) * x_c * map->i + cos(map->a) * y_c * \
			map->i - map->map[y + 1][x] * map->z;
	}
	map->x[0] += 1920 / 2;
	map->y[0] += 1080 / 2;
	map->x[1] += 1920 / 2;
	map->y[1] += 1080 / 2;
}

void	ft_draw(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	create_img(map);
	while (++y != map->width)
	{
		x = -1;
		while (++x != map->length)
		{
			map->x[0] = x;
			map->y[0] = y;
			if (x + 1 < map->length)
			{
				ft_transformation(map, x, y, 1);
				draw_lines(map);
			}
			if (y + 1 < map->width)
			{
				ft_transformation(map, x, y, 0);
				draw_lines(map);
			}
		}
	}
	destroy_img(map);
}
