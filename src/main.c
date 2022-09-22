/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:00:50 by dgross            #+#    #+#             */
/*   Updated: 2022/09/22 16:24:16 by dgross           ###   ########.fr       */
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
	t_map	map;

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
		read_map(fd, &map);
		create_map(&map, &fdf);
		//memset(fdf.img->pixels, 255, fdf.img->width * fdf.img->height * sizeof(int));
		mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
		mlx_loop_hook(fdf.mlx, &hook, &fdf);
		mlx_loop(fdf.mlx);
		mlx_terminate(fdf.mlx);
	}
	return (0);
}
