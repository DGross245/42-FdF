/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:25 by dgross            #+#    #+#             */
/*   Updated: 2022/09/27 17:11:41 by dgross           ###   ########.fr       */
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
		if (*lst != NULL)
		{
			new_lst->next = *lst;
			(*lst)->prev = new_lst;
			*lst = new_lst;
			(*lst)->prev = NULL;
		}
		else
		{
			*lst = new_lst;
			new_lst->prev = NULL;
		}
	}
}
//void	ft_add_front(t_grid **lst, t_grid *new_lst)
//{
//	if (lst)
//	{
//		if (new_lst)
//			new_lst->next = *lst;
//		*lst = new_lst;
//	}
//}

t_grid	*ft_lastnode(t_grid *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next != NULL)	
			lst = lst->next;
		else
			break; 
	}
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
