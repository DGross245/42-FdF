/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:46:59 by dgross            #+#    #+#             */
/*   Updated: 2022/10/01 20:41:49 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_point	point_init(void)
{
	t_point	coords;

	//coords = (t_point *)malloc(sizeof(t_point));
	coords.x_offset = 0;
	coords.y_offset = 0;
	coords.x = 0;
	coords.y = 0;
	coords.z_incr = 1;
	coords.angle1 = 0;
	coords.angle2 = 0;
	coords.angle3 = 0;
	return (coords);
}

t_cam	cam_init(t_map *map)
{
	t_cam	camera;
	int		i;

	//camera = (t_cam *)malloc(sizeof(t_cam));
	i = min((HEIGHT / map->height) / 2, (WIDTH / map->width) / 2);
	if (i == 1)
		i++;
	camera.zoom = i;
	camera.projection = 1;
	camera.prev_zoom = i;
	return (camera);
}

void	free_all(t_fdf *fdf)
{
	t_grid	*tmp;
	char	*tmp1;

	free(fdf->map.str);
	free(fdf->map.colour);
	while (fdf->map.stack != NULL)
	{
		tmp = fdf->map.stack;
		tmp1 = fdf->map.stack->grid;
		fdf->map.stack = fdf->map.stack->next;
		free(tmp1);
		free(tmp);
	}
}

t_fdf	*init(t_fdf *fdf)
{
	fdf->map.cam = cam_init(&fdf->map);
	fdf->map.stack->point = point_init();
	return (fdf);
}
