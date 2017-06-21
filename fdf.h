/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:11:51 by efedorov          #+#    #+#             */
/*   Updated: 2017/02/23 17:27:36 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# define BUFF_SIZE 100

typedef struct		s_map
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*tmp;
	float		a;
	int			x[2];
	int			y[2];
	int			**map;
	int			red;
	int			green;
	int			blue;
	int			length;
	int			width;
	int			i;
	int			z;
}					t_map;

int					ft_init(t_map *map);
void				ft_fill(t_map *map, char **tmp, int x, int y);
void				put_pxl(t_map *map, int x, int y);
void				ft_draw(t_map *map);
int					loop_draw(t_map *map);
int					key_func(int keycode, t_map *map);
int					ft_atoi(char *num);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					get_next_line(const int fd, char **line);

#endif
