/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:00:50 by dgross            #+#    #+#             */
/*   Updated: 2022/10/03 15:20:33 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf;

	errno = 0;
	fdf.map.stack = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 1)
			ft_exit("fd error");
		init_fdf(&fdf);
		read_map(fd, &fdf);
		init(&fdf);
		create_map(&fdf.map, &fdf);
		mlx_loop_hook(fdf.mlx, &hook, &fdf);
		mlx_loop(fdf.mlx);
		mlx_terminate(fdf.mlx);
		free_all(&fdf);
		return (0);
	}
	ft_exit("wrong input");
}

void	ft_exit(char *str)
{
	perror(str);
	exit(0);
}

void	ft_exit2(char *str, t_fdf *fdf)
{
	free_all(fdf);
	mlx_terminate(fdf->mlx);
	perror(str);
	exit(0);
}
