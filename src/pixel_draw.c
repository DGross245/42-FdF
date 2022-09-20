/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:17 by dgross            #+#    #+#             */
/*   Updated: 2022/09/20 17:40:41 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "MLX42.h"

void	creat_map(t_map *map, t_map *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_line(make_point(x, y, map), make_point(x, y, map), map);
			y++;
		}
		x++;
	}
}

t_point	make_point(int x, int y, t_map *map)
{
	t_point	*coords;

	coords = map->point;
	coords->x = x;
	coords->y = y;
	coords->z = ft_atoi(map->stack->grid);
	coords->c = 0;
	return (coords);
}

void	draw_line(t_point start, t_point end, t_fdf *fdf)
{
	int	x;

	swap_coords(start, end);
	get_data(start, end);
	if (check(start, end))
	{
		while (start.x < end.x)
		{
			mlx_put_pixel(fdf->image, /*Y*/, x, /*farbe*/);
			mlx_put_pixel(fdf->image, /*Y*/ - 1, x, /*farbe*/);
			/*Y*/ += gradient;
		}
	}
	else
	{
		while (start.x < end.x)
		{
			mlx_put_pixel(fdf->image, x, /*Y*/, /*farbe*/);
			mlx_put_pixel(fdf->image, x, /*Y*/ - 1, /*farbe*/);
			/*Y*/ += gradient;
		}
	}
}

void	get_data(t_point start, t_point end)
{
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx == 0.0)
		gradient = 1.0;
	else
		gradient = dy / dx;
	xend = round (x0);
	yend = y0 + gradient * (xend - x0);
	xgap = fpart(x0 + 0.5);
	xpxl1 = xend;
	ypxl1 = ipart(yend);
}

void	swap_coords(t_point start, t_points end)
{
	if (check(start, end))
	{
		swap(start.x, start.y);
		swap(end.x, end.y);
	}
	else
	{
		swap(start.x, end.x);
		swap(start.y, end.y);
	}
}

int	check(t_point *start, t_point *end)
{
	if (ft_abs(end.y - start.y) > ft_abs(end.x - start.x))
		return (1);
	return (0);
}
