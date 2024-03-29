/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:15 by dgross            #+#    #+#             */
/*   Updated: 2024/03/29 18:47:04 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*line_remove(char *str)
{
	char	*new;

	if (str[ft_strlen(str) - 1] != '\n')
		return (str);
	new = malloc(sizeof(char) * ft_strlen(str) + 1);
	ft_strlcpy(new, str, ft_strlen(str));
	new[ft_strlen(str)] = '\0';
	free(str);
	return (new);
}

int	read_map(int fd, t_fdf *fdf)
{
	char	*line;
	int		height;
	int		error;

	error = 0;
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = line_remove(line);
		if (get_stats(line, fdf) == -1)
			error = -1;
		free(line);
		height++;
		line = get_next_line(fd);
	}
	if (!fdf->map.stack)
		ft_exit2("Wrong File", fdf);
	free(line);
	fdf->map.height = height;
	close(fd);
	if (error == -1)
		ft_exit2("Read error", fdf);
	return (0);
}

int	get_stats(char *line, t_fdf *fdf)
{
	char	**coords;
	int		i;
	int		width;
	int		error;

	error = 0;
	i = 0;
	width = 0;
	coords = ft_split(line, ' ');
	while (coords[i])
	{
		if (ft_add_front(&fdf->map.stack, ft_newlist(coords[i])) == -1)
			error = -1;
		i++;
		width++;
	}
	free_coords(coords);
	fdf->map.width = width;
	if (error == -1)
		return (-1);
	return (0);
}

void	free_coords(char **coords)
{
	int		i;

	i = 0;
	while (coords[i])
		free(coords[i++]);
	free(coords);
}

char	*add_stuff(char *hex)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_malloc(sizeof(char) * 11);
	while (hex[i] != '\0')
	{
		str[i] = hex[i];
		i++;
	}
	str[i] = 'F';
	str[i + 1] = 'F';
	str[i + 2] = '\0';
	i = 0;
	free(hex);
	return (str);
}
