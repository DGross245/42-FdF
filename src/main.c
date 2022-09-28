/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:00:50 by dgross            #+#    #+#             */
/*   Updated: 2022/09/28 20:41:09 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include "fdf.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf;

	fdf.map.stack = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 1)
			return (0); // MUSS EIN ERROR SEIN
		fdf.mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
		if (fdf.mlx == NULL)
			return (0); // MUSS EIN ERROR SEIN
		fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
		if (!fdf.img)
			return (0); // MUSS EIN ERROR SEIN
		read_map(fd, &fdf.map);
		fdf.map.cam = cam_init(&fdf.map);
		fdf.map.stack->point = point_init();
		create_map(&fdf.map, &fdf);
		mlx_loop_hook(fdf.mlx, &hook, &fdf);
		mlx_loop(fdf.mlx);
		mlx_terminate(fdf.mlx);
	}
	return (0);
}

t_point	point_init(void)
{
	t_point	coords;

	coords.x_offset = 0;
	coords.y_offset = 0;
	coords.x = 0;
	coords.y = 0;
	coords.z_incr = 1;
	return (coords);
}

t_cam	cam_init(t_map *map)
{
	t_cam	camera;
	int		i;

	i = min((HEIGHT / map->height) / 2, (WIDTH / map->width) / 2);
	if (i == 1)
		i++;
	camera.zoom = i;
	camera.projection = 1;
	return (camera);
}
