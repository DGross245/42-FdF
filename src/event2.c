/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:59:12 by dgross            #+#    #+#             */
/*   Updated: 2022/10/01 23:56:03 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_8)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_4)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_6)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_2)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_7)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_9))
		angel(fdf);
}

void	angel(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_8))
		fdf->map.stack->point.angle1 += 0.10;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_4))
		fdf->map.stack->point.angle2 -= 0.10;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_2))
		fdf->map.stack->point.angle1 -= 0.10;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_6))
		fdf->map.stack->point.angle2 += 0.10;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_7))
		fdf->map.stack->point.angle3 -= 0.10;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_9))
		fdf->map.stack->point.angle3 += 0.10;
	re_draw(fdf);
}
