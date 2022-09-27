/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:43:30 by dgross            #+#    #+#             */
/*   Updated: 2022/09/28 01:37:47 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "libft.h"

int	check(t_point start, t_point end)
{
	if (ft_abs(end.y - start.y) > ft_abs(end.x - start.x))
		return (1);
	return (0);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	ft_listsize(t_grid *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		ft_bzero(ptr, size);
	return (ptr);
}
