/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:54:20 by dgross            #+#    #+#             */
/*   Updated: 2022/10/03 18:41:31 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include "libft.h"

void	iso(float *x, float *y, float *z)
{
	float	x_tmp;
	float	y_tmp;

	x_tmp = *x;
	y_tmp = *y;
	*x = (x_tmp - y_tmp) * cos(0.523599);
	*y = -*z + (x_tmp + y_tmp) * sin(0.523599);
}

void	rotate_x(float *y, float *z, float angle1)
{
	float	y_tmp;

	y_tmp = *y;
	*y = y_tmp * cos(angle1) - *z * sin(angle1);
	*z = y_tmp * sin(angle1) + *z * cos(angle1);
}

void	rotate_y(float *x, float *z, float angle2)
{
	float	x_tmp;

	x_tmp = *x;
	*x = x_tmp * cos(angle2) + *z * sin(angle2);
	*z = -x_tmp * sin(angle2) + *z * cos(angle2);
}

void	rotate_z(float *x, float *y, float angle3)
{
	float	x_tmp;

	x_tmp = *x;
	*x = x_tmp * cos(angle3) - *y * sin(angle3);
	*y = x_tmp * sin(angle3) + *y * cos(angle3);
}

void	converter(t_fdf *fdf)
{
	t_grid	*head;
	int		i;
	int		listsize;

	i = 0;
	fdf->map.str = ft_malloc(fdf->map.width * fdf->map.height * sizeof(int));
	fdf->map.colour = ft_malloc(fdf->map.width * fdf->map.height * sizeof(int));
	head = lastnode(fdf->map.stack);
	listsize = ft_listsize(fdf->map.stack);
	while (listsize != 0)
	{
		if (!ft_isnumber(head->grid, 10))
			ft_exit2("read error", fdf);
		fdf->map.str[i] = ft_atoi(head->grid);
		fdf->map.colour[i] = head->colour;
		head = head->prev;
		listsize--;
		i++;
	}
}
