/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 12:03:42 by efedorov          #+#    #+#             */
/*   Updated: 2017/02/23 14:27:25 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_into_stock(int fd, char *stock)
{
	int		size;
	int		count;
	char	*buff;
	char	*str;

	str = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	buff = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	size = read(fd, str, BUFF_SIZE);
	str[size] = '\0';
	stock = str;
	count = size;
	while (size > 0)
	{
		size = read(fd, buff, BUFF_SIZE);
		buff[size] = '\0';
		count += size;
		if (size != 0)
			stock = ft_strjoin(stock, (const char*)buff);
	}
	stock[count] = '\0';
	return (stock);
}

char	*write_into_stock(char *stock, char **line)
{
	int		length;
	int		i;

	length = ft_strlen(stock);
	i = 0;
	if (stock[i] && stock[i] != '\n')
	{
		while (stock[i] && stock[i] != '\n')
			i++;
		*line = ft_strsub(stock, 0, i);
		stock = ft_strsub(stock, ++i, length);
		return (stock);
	}
	else if (stock[i] == '\n')
	{
		*line = ft_strnew(0);
		stock = ft_strsub(stock, 1, length);
		return (stock);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*fd_stock[4096];

	if (!line || ((read(fd, NULL, 0) == -1)) || BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	*line = NULL;
	if (fd_stock[fd] == NULL)
		if (!(fd_stock[fd] = read_into_stock(fd, fd_stock[fd])))
			return (-1);
	fd_stock[fd] = write_into_stock(fd_stock[fd], line);
	if (fd_stock[fd] == NULL)
		return (0);
	return (1);
}
