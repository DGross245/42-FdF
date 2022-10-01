/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:25:18 by dgross            #+#    #+#             */
/*   Updated: 2022/10/01 16:52:22 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "MLX42.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		zoom(fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_EQUAL)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_DIVIDE))
		move(fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_1)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_3))
		projection(fdf);
}

void	re_draw(t_fdf *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		return ;
	free(fdf->map.str);
	free(fdf->map.colour);
	create_map(&fdf->map, fdf);
}

void	projection(t_fdf *fdf)
{
	fdf->map.stack->point.angle1 = 0;
	fdf->map.stack->point.angle2 = 0;
	fdf->map.stack->point.z_incr = 1;
	fdf->map.stack->point.angle3 = 0;
	fdf->map.cam.zoom = fdf->map.cam.prev_zoom;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_1))
		fdf->map.cam.projection = 1;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_3))
		fdf->map.cam.projection = 3;
	re_draw(fdf);
}

void	zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
	{
		if (fdf->map.cam.zoom < 75)
			fdf->map.cam.zoom += 1;
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
	{
		if (fdf->map.cam.zoom > 3)
			fdf->map.cam.zoom -= 1;
	}
	re_draw(fdf);
}

void	move(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->map.stack->point.x_offset -= 15;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->map.stack->point.x_offset += 15;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->map.stack->point.y_offset -= 15;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->map.stack->point.y_offset += 15;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_EQUAL))
		fdf->map.stack->point.z_incr += 0.1;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_DIVIDE))
		fdf->map.stack->point.z_incr -= 0.1;
	re_draw(fdf);
}
