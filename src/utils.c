/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:26:25 by dgross            #+#    #+#             */
/*   Updated: 2022/10/03 00:58:29 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_grid	*ft_newlist(char *coords)
{
	t_grid	*node;
	char	**colour;
	int		error;

	error = 0;
	node = malloc(sizeof(t_grid));
	if (node == NULL)
		return (NULL);
	colour = ft_split(coords, ',');
	if (ft_check(colour) == -1)
		error = -1;
	if (colour[1])
		node->colour = ft_atoi_base(colour[1], 16);
	else
		node->colour = 0;
	node->grid = ft_strdup(colour[0]);
	node->next = NULL;
	free_coords(colour);
	if (error == -1)
	{
		free(node->grid);
		free (node);
		return (NULL);
	}
	return (node);
}

int	ft_add_front(t_grid **lst, t_grid *new_lst)
{
	if (new_lst == NULL)
		return (-1);
	if (lst != NULL)
	{
		new_lst->next = *lst;
		new_lst->prev = NULL;
		if (*lst != NULL)
			(*lst)->prev = new_lst;
		*lst = new_lst;
		return (1);
	}
	return (0);
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
