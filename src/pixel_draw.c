/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:17 by dgross            #+#    #+#             */
/*   Updated: 2022/09/22 17:52:47 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "MLX42.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

void	create_map(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				draw_line(calc_coord(make_point(x, y, map)),
					calc_coord(make_point(x + 1, y, map)), fdf, map);
			if (y != map->height - 1)
				draw_line(calc_coord(make_point(x, y, map)),
					calc_coord(make_point(x, y + 1, map)), fdf, map);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
}

t_point	make_point(int x, int y, t_map *map)
{
	t_point	*coords;

	coords = &map->stack->point;
	coords->x = x;
	coords->y = y;
	coords->z = ft_atoi(map->stack->grid);
	coords->c = 0;
	return (*coords);
}

void	draw_line(t_point start, t_point end, t_fdf *fdf, t_map *map)
{
	swap_coords(start, end);
	get_data(start, end, map);
	if (check(start, end))
	{
		while (start.x < end.x)
		{
			mlx_put_pixel(fdf->img, floor(start.y), start.x, 0xFFFFFFFF);
			mlx_put_pixel(fdf->img, floor(start.y) - 1, start.x, 0xFFFFFFFF);
			start.y += map->stack->gradient;
			start.x++;
		}
	}
	else
	{
		while (start.x < end.x)
		{
			printf("%d\n", start.y);
			mlx_put_pixel(fdf->img, start.x, floor(start.y), 0xFFFFFFFF);
			mlx_put_pixel(fdf->img, start.x, floor(start.y) - 1, 0xFFFFFFFF);
			start.y += map->stack->gradient;
			start.x++;
		}
	}
}

void	get_data(t_point start, t_point end, t_map *map)
{
	t_grid	*tmp;

	tmp = map->stack;
	tmp->dx = end.x - start.x;
	tmp->dy = end.y - start.x;
	if (tmp->dx == 0.0)
		tmp->gradient = 1;
	else
		tmp->gradient = tmp->dy / tmp->dx;
}

void	swap_coords(t_point start, t_point end)
{
	if (check(start, end))
	{
		swap(&start.x, &start.y);
		swap(&end.x, &end.y);
	}
	else
	{
		swap(&start.x, &end.x);
		swap(&start.y, &end.y);
	}
}

void	iso(t_point coords)
{
	int	temp_x;
	int	temp_y;

	temp_x = coords.x;
	temp_y = coords.y;
	coords.x = (temp_x - temp_y) * cos(0.5);
	coords.y = (temp_x + temp_y) * sin(0.5);
}

t_point	calc_coord(t_point coords)
{
	iso(coords);
	coords.x += WIDTH / 2;
	coords.y += coords.z * -1 + HEIGHT / 2;
	return (coords);
}

