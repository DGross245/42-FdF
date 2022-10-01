/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:00:50 by dgross            #+#    #+#             */
/*   Updated: 2022/10/02 00:03:19 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

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
		init(&fdf);
		create_map(&fdf.map, &fdf);
		mlx_loop_hook(fdf.mlx, &hook, &fdf);
		mlx_loop_hook(fdf.mlx, &rotate, &fdf);
		mlx_loop(fdf.mlx);
		mlx_terminate(fdf.mlx);
		free_all(&fdf);
	}
	return (0);
}
