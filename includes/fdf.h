/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:00:36 by dgross            #+#    #+#             */
/*   Updated: 2022/09/22 17:52:13 by dgross           ###   ########.fr       */
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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	c;
}t_point;

typedef struct s_grid
{
	char			*grid;
	t_point			point;
	double			dx;
	double			dy;
	double			gradient;
	double			inty;
	struct s_grid	*next;
	struct s_grid	*prev;	
}t_grid;

typedef struct s_map
{
	int		height;
	int		width;
	t_grid	*stack;
}t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*str_img;
}			t_fdf;
///////////////////////////////////////////////////
/////////		read_map.c		///////////////////
///////////////////////////////////////////////////

int			read_map(int fd, t_map *map);
void		get_stats(char *line, t_map *map);
void		free_coords(char **coords);

///////////////////////////////////////////////////
/////////		pixel_draw.c		///////////////
///////////////////////////////////////////////////

void		create_map(t_map *map, t_fdf *fdf);
t_point		make_point(int x, int y, t_map *map);
void		draw_line(t_point start, t_point end, t_fdf *fdf, t_map *map);
void		get_data(t_point start, t_point end, t_map *map);
void		swap_coords(t_point start, t_point end);

///////////////////////////////////////////////////
/////////		utils.c		  /////////////////////
///////////////////////////////////////////////////

t_grid		*ft_newlist(char *line);
void		ft_add_to_back(t_grid **lst, t_grid *new_lst);
t_grid		*ft_lastnode(t_grid *lst);
int			ft_abs(int x);
void		swap(int *a, int *b);

///////////////////////////////////////////////////
/////////		utils2.c		  /////////////////
///////////////////////////////////////////////////

int			check(t_point start, t_point end);

///////////////////////////////////////////////////
/////////		event.c		  /////////////////////
///////////////////////////////////////////////////

void		hook(void *param);

t_point		make_iso(t_point coords);
t_point	calc_coord(t_point coords);
void	iso(t_point coords);

#endif