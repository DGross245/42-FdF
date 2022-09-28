/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:25:18 by dgross            #+#    #+#             */
/*   Updated: 2022/09/28 20:41:17 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "MLX42.h"
#include "libft.h"
#include <stdio.h>

void	hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		zoom(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
		move(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		projection(fdf);
}

void	re_draw(t_fdf *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		return ;
	create_map(&fdf->map, fdf);
}

void	projection(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		fdf->map.cam.projection = 1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		fdf->map.cam.projection = 2;
	re_draw(fdf);
}

void	zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
	{
		if (fdf->map.cam.zoom < 75)
			fdf->map.cam.zoom += 1;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
	{
		if (fdf->map.cam.zoom > 3)
			fdf->map.cam.zoom -= 1;
	}
	re_draw(fdf);
}

void	move(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->map.stack->point.x_offset -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->map.stack->point.x_offset += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->map.stack->point.y_offset -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->map.stack->point.y_offset += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL))
		fdf->map.stack->point.z_incr += 1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
		fdf->map.stack->point.z_incr -= 1;
	re_draw(fdf);
}
