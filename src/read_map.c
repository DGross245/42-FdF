/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:15 by dgross            #+#    #+#             */
/*   Updated: 2022/09/28 01:24:27 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*line_remove(char *str)
{
	char	*new;

	if (str[ft_strlen(str) - 1] != '\n')
		return (str);
	new = malloc(sizeof(char) * ft_strlen(str));
	ft_strlcpy(new, str, ft_strlen(str));
	new[ft_strlen(str)] = '\0';
	free(str);
	return (new);
}

int	read_map(int fd, t_map *map)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = line_remove(line);
		get_stats(line, map);
		free(line);
		height++;
		line = get_next_line(fd);
	}
	map->height = height;
	return (0);
}

void	get_stats(char *line, t_map *map)
{
	char	**coords;
	int		i;
	int		width;

	i = 0;
	width = 0;
	coords = ft_split(line, ' ');
	while (coords[i])
	{
		ft_add_front(&map->stack, ft_newlist(coords[i]));
		i++;
		width++;
	}
	free_coords(coords);
	map->width = width;
}

void	free_coords(char **coords)
{
	int		i;

	i = 0;
	while (coords[i])
		free(coords[i++]);
	free(coords);
}

void	converter(t_map *map)
{
	t_grid	*head;
	int		*str;
	int		size;
	int		i;
	int		listsize;

	i = 0;
	size = map->width * map->height;
	str = malloc(sizeof(int) * size);
	head = lastnode(map->stack);
	listsize = ft_listsize(map->stack);
	while (listsize != 0)
	{
		str[i] = ft_atoi(head->grid);
		head = head->prev;
		listsize--;
		i++;
	}
	map->str = ft_int_strdup(str, size);
}
