/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:25 by dgross            #+#    #+#             */
/*   Updated: 2022/09/21 21:10:38 by dgross           ###   ########.fr       */
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

void	ft_add_to_back(t_grid **lst, t_grid *new_lst)
{
	t_grid	*tmp;

	tmp = NULL;
	if (*lst != NULL)
	{
		tmp = ft_lastnode(*lst);
		new_lst->prev = tmp;
		tmp->next = new_lst;
	}
	else
	{
		*lst = new_lst;
		new_lst->prev = NULL;
	}
}

t_grid	*ft_lastnode(t_grid *lst)
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
