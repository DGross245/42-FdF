/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:17 by dgross            #+#    #+#             */
/*   Updated: 2022/09/28 01:57:04 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "MLX42.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void	create_map(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	converter(map);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				draw_line(calc_coord(map, make_point(x, y, map)),
					calc_coord(map, make_point(x + 1, y, map)), fdf);
			if (y != map->height - 1)
				draw_line(calc_coord(map, make_point(x, y, map)),
					calc_coord(map, make_point(x, y + 1, map)), fdf);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
}

t_point	make_point(int x, int y, t_map *map)
{
	t_point	coords;

	coords.x = x;
	coords.y = y;
	coords.z = map->str[map->width * y + x];
	return (coords);
}

void	draw_line(t_point start, t_point end, t_fdf *fdf)
{
	int			x;
	double		x_step;
	double		y_step;
	int			max_step;

	x = 0;
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_step = max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max_step;
	y_step /= max_step;
	while (x < max_step)
	{
		x++;
		if (start.x > 0 && start.y > 0 && start.x < WIDTH && start.y < HEIGHT)
			mlx_put_pixel(fdf->img, start.x, start.y, 0xFFFFFFFF);
		start.x += x_step;
		start.y += y_step;
	}
}

void	iso(float *x, float *y, float z)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point	calc_coord(t_map *map, t_point coords)
{
	coords.x *= map->cam.zoom;
	coords.y *= map->cam.zoom;
	coords.x -= (map->cam.zoom * map->width) / 2;
	coords.y -= (map->cam.zoom * map->height) / 2;
	iso(&coords.x, &coords.y, coords.z);
	coords.x += WIDTH / 2;
	coords.y += (HEIGHT + map->cam.zoom * map->height) / 2;
	return (coords);
}
