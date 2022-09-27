/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:15 by dgross            #+#    #+#             */
/*   Updated: 2022/09/27 16:11:17 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int	read_map(int fd, t_map *map)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		get_stats(line, map);
		free(line);
		line = get_next_line(fd);
		height++;
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
		ft_add_front(&map->stack, ft_newlist(coords[i++]));
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
