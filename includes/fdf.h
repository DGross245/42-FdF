/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:00:36 by dgross            #+#    #+#             */
/*   Updated: 2022/09/20 17:40:10 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FIXEN = änderungen im Header werden beim maken nicht erkannst, 
// sprich make macht dann nichts.
// nochmal nachlesen obs true ist und dann auch in Libft ändern ! $
// wenn was bei libft geändert wird reicht ein make bei FdF nicht. 
// muss gefixt werden sollte libft auch checken obs es ok ist.

#ifndef FDF_H
# define FDF_H

# define HEIGHT				1080
# define WIDTH				1920
# include "MLX42.h"

typedef struct s_grid
{
	char			*grid;
	t_points		*point;
	struct s_grid	*next;
	struct s_grid	*prev;	
}t_grid;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	c;
}t_point;

typedef struct s_map
{
	int		height;
	int		width;
	t_grid	*stack;
	//t_cam	*view; 
}t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*str_img;
}			t_fdf;

//typedef struct s_cam
//{
//}t_cam;

void		hook(void *param);
int			read_map(int fd, t_map *map);
t_grid		*ft_newlist(char *line);
void		ft_add_to_back(t_grid **lst, t_grid *new_lst);
t_grid		*ft_lastnode(t_grid *lst);
void		free_coords(char **coords);
void		get_stats(char *line, t_map *map);
void		swap_coords(int *a, int *b);

#endif