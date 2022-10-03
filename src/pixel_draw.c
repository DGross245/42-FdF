/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:17 by dgross            #+#    #+#             */
/*   Updated: 2022/10/03 18:41:44 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "MLX42.h"
#include "libft.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

void	create_map(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	converter(fdf);
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
	map->stack->point.x = x;
	map->stack->point.y = y;
	map->stack->point.z = map->str[map->width * y + x];
	if (map->colour[0] != 0)
		map->stack->point.z_colour = map->colour[map->width * y + x];
	else
		map->stack->point.z_colour = 0xFFFFFFFF;
	return (map->stack->point);
}

void	draw_line(t_point start, t_point end, t_fdf *fdf)
{
	int			x;
	double		dx;
	double		dy;
	int			xend;

	x = 0;
	dx = end.x - start.x;
	dy = end.y - start.y;
	xend = max(ft_abs(dx), ft_abs(dy));
	dx /= xend;
	dy /= xend;
	while (x < xend)
	{
		if (start.x > 0 && start.y > 0 && start.x < WIDTH && start.y < HEIGHT)
			mlx_put_pixel(fdf->img, start.x, start.y, start.z_colour);
		start.x += dx;
		start.y += dy;
		x++;
	}
}

t_point	calc_coord(t_map *map, t_point coords)
{
	coords.x *= map->cam.zoom;
	coords.y *= map->cam.zoom;
	coords.z *= map->cam.zoom / 2;
	coords.z *= coords.z_incr;
	coords.x -= ((map->cam.zoom * map->width) / 2);
	coords.y -= ((map->cam.zoom * map->height) / 2);
	rotate_x(&coords.y, &coords.z, map->stack->point.angle1);
	rotate_y(&coords.x, &coords.z, map->stack->point.angle2);
	rotate_z(&coords.x, &coords.y, map->stack->point.angle3);
	if (map->cam.projection == 1)
		iso(&coords.x, &coords.y, &coords.z);
	coords.x += (WIDTH / 2) + coords.x_offset;
	coords.y += (HEIGHT / 2) + coords.y_offset;
	return (coords);
}
