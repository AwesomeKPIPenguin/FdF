/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:35:45 by domelche          #+#    #+#             */
/*   Updated: 2018/03/07 17:28:16 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"

# include <stdio.h>

# define MAX(x, y) (x < y) ? y : x
# define MIN(x, y) (x < y) ? x : y

# define PI				3.14159265

# define ESC			0x35
# define ARR_UP			0x7E
# define ARR_DOWN		0x7D
# define ARR_RIGHT		0x7C
# define ARR_LEFT		0x7B
# define ARR_LESS		0x2B
# define ARR_MORE		0x2F
# define W				0x0D
# define A				0x00
# define S				0x01
# define D				0x02
# define PLUS			0x45
# define MINUS			0x4E
# define C				0x08

# define WIN_X			1000
# define WIN_Y			700

# define RAINBOW_DIF	1280.0

# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define DARK_RED		0x800000
# define RED			0xFF0000
# define LIGHT_RED		0xFF8080
# define RED_GREEN		0xFFFF00
# define DARK_GREEN		0x008000
# define GREEN			0x00FF00
# define LIGHT_GREEN	0x80FF80
# define GREEN_BLUE 	0x00FFFF
# define DARK_BLUE		0x000080
# define BLUE			0x0000FF
# define LIGHT_BLUE		0x8080FF
# define RED_BLUE		0xFF00FF

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			colour;
}				t_point;

typedef struct	s_map
{
	int			width;
	int			height;
	int			scale;
	t_point		*move_vector;
	double		rotation_angles[3];
	int			z_min;
	int			z_max;
	int			colour_set;
	int			is_colourful;
	t_point		*center;
	t_point		***points;
	t_point		***origin;
}				t_map;

typedef struct	s_img
{
	void		*ptr;
	int			width;
	int			height;
	char		*data;
	int			*z_data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_params
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
}				t_params;

/*
**	main.c
*/

void			ft_error(char *msg);

/*
**	key_hooks.c
*/

int				ft_exit_hook(int key_code, void *p);
int				ft_key_hook(int key_code, void *p);

/*
**	info.c
*/

void			ft_info(t_params *p);

/*
**	point.c
*/

t_point			*ft_pointnew(int x, int y, int z, int colour);
t_point			*ft_point_clone(t_point *point);
void			ft_foreach_point(t_map *map, void (*ft)(), int mode);

/*
**	map.c
*/

t_map			*ft_mapnew(int width, int height);

/*
**	ft_getmap.c
*/

t_map			*ft_getmap(char *file);

/*
**	map_move.c
*/

void			ft_map_move(t_map *map, int x, int y, int z);

/*
**	map_rotate.c
*/

void			ft_map_rotate(t_map *map, double alpha, double beta,
					double gamma);

/*
**	map_scale.c
*/

int				ft_is_at_center(t_map *map);
void			ft_map_scale(t_map *map, int scale);

/*
**	ft_optimize.c
*/

void			ft_optimize(t_map *map);

/*
**	ft_render_map.c
*/

void			ft_render_map(t_params *p);
void			ft_normalize_map(t_map *map);

/*
**	image.c
*/

t_img			*ft_imgnew(void *mlx, int width, int height);
void			ft_clear_img(t_img *img);

/*
**	params.c
*/

t_params		*ft_paramsnew(void *mlx, void *win, t_img *img, t_map *map);

/*
**	colour.c
*/

double			*ft_colour_to_rgb(unsigned int colour);
int				ft_rgb_to_colour(double *rgb);
int				ft_get_colour(char *str);
void			ft_dist_colours(t_map *map);

/*
**	colour_rainbow.c
*/

int				ft_get_rainbow_index(int colour);
int				ft_rainbow(int step);

/*
**	colour_steps.c
*/

double			*ft_get_c_steps(int colour1, int colour2, int i);
void			ft_make_step(double *arg, double *rgb, double *c_steps);

/*
**	ft_draw.c
*/

void			ft_draw_line(t_img *img, t_point *point1, t_point *point2,
					int is_colourful);
void			ft_draw_line_rnbw(t_img *img, t_point *point1, t_point *point2,
					int is_colourful);

#endif
