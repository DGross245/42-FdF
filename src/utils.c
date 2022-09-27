/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:25 by dgross            #+#    #+#             */
/*   Updated: 2022/09/27 21:51:40 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_grid	*ft_newlist(char *coords)
{
	t_grid	*node;

	node = malloc(sizeof(t_grid));
	if (node == NULL)
		return (NULL);
	node->grid = ft_strdup(coords);
	node->next = NULL;
	return (node);
}

void	ft_add_front(t_grid **lst, t_grid *new_lst)
{
	if (lst != NULL)
	{
		new_lst->next = *lst;
		new_lst->prev = NULL;
		if (*lst != NULL)
			(*lst)->prev = new_lst;
		*lst = new_lst;
	}
}

t_grid	*lastnode(t_grid *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
