/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:38:18 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/02 12:57:14 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"

void	ft_size(char *file, t_map *map)
{
	int		fd;
	int		new_x;
	int		i;
	char	*line;

	i = -1;
	new_x = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		map->length = 0;
		while (line[++i])
		{
			if (line[i] >= '0' && line[i] <= '9')
				map->length++;
		}
		if (map->length > new_x)
			new_x = map->length;
		map->width++;
		if (line)
			free(line);
	}
	map->length = new_x;
	close(fd);
}

void	ft_create_map(char *file, t_map *map)
{
	int		fd;
	int		x;
	int		y;
	char	**tmp;
	char	*line;

	y = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return ;
	tmp = NULL;
	map->map = (int**)malloc(sizeof(int*) * map->width);
	while (get_next_line(fd, &line) == 1 && y != map->width)
	{
		x = 0;
		map->map[y] = (int*)malloc(sizeof(int) * map->length);
		tmp = ft_strsplit(line, ' ');
		if (tmp)
			ft_fill(map, tmp, x, y);
		if (tmp)
			free(tmp);
		y++;
	}
	close(fd);
}

int		key_func_color(int keycode, t_map *map)
{
	if (keycode == 15 && ((map->red + 15) <= 255))
		map->red += 15;
	else if (keycode == 5 && ((map->green + 15) <= 255))
		map->green += 15;
	else if (keycode == 11 && ((map->blue + 15) <= 255))
		map->blue += 15;
	else if (keycode == 14 && ((map->red - 15) >= 0))
		map->red -= 15;
	else if (keycode == 3 && ((map->green - 15) >= 0))
		map->green -= 15;
	else if (keycode == 9 && ((map->blue - 15) >= 0))
		map->blue -= 15;
	else if (keycode == 10)
	{
		map->red = 0;
		map->green = 0;
		map->blue = 0;
	}
	return (0);
}

int		key_func(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 27 && (map->i - 2) > 0)
		map->i -= 2;
	else if (keycode == 24 && (map->i + 2) < 170)
		map->i += 2;
	else if (keycode == 15 || keycode == 5 || keycode == 11 || keycode == 14 ||
		keycode == 10 || keycode == 9 || keycode == 3)
		key_func_color(keycode, map);
	else if (keycode == 123)
		map->a -= 0.04;
	else if (keycode == 124)
		map->a += 0.04;
	else if (keycode == 69 && ((map->z + 1) <= 20))
		map->z += 1;
	else if (keycode == 78 && ((map->z - 1) >= -20))
		map->z -= 1;
	return (0);
}

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_putendl("Invalid amount of arguments");
		exit(0);
	}
	map = (t_map*)malloc(sizeof(t_map));
	if (ft_init(map) == 1)
		return (0);
	ft_size(argv[1], map);
	ft_create_map(argv[1], map);
	mlx_hook(map->win, 2, 3, key_func, map);
	mlx_loop_hook(map->mlx, &loop_draw, map);
	mlx_loop(map->mlx);
	return (0);
}
