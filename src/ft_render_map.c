/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:52:10 by domelche          #+#    #+#             */
/*   Updated: 2018/03/07 17:31:38 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_point	*ft_get_left_point(t_map *map, int i, int j)
{
	int		k;

	k = 1;
	while (!map->points[i][j - k])
		k++;
	return (map->points[i][j - k]);
}

static t_point	*ft_get_upper_point(t_map *map, int i, int j)
{
	int		k;

	k = 1;
	while (!map->points[i - k][j])
		k++;
	return (map->points[i - k][j]);
}

static void		ft_draw_map(t_params *p, void (*ft_draw_line)())
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->map->height / p->map->scale)
	{
		j = -1;
		while (++j < p->map->width / p->map->scale)
		{
			if (!p->map->points[i][j])
				continue ;
			if (j >= 1)
				ft_draw_line(p->img, p->map->points[i][j],
					ft_get_left_point(p->map, i, j), p->map->is_colourful);
			if (i >= 1)
				ft_draw_line(p->img, p->map->points[i][j],
					ft_get_upper_point(p->map, i, j), p->map->is_colourful);
		}
	}
}

void			ft_render_map(t_params *p)
{
	ft_clear_img(p->img);
	ft_draw_map(p, (p->map->colour_set) ? ft_draw_line : ft_draw_line_rnbw);
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->img->ptr, 0, 0);
}

void			ft_normalize_map(t_map *map)
{
	int		scale;

	scale = MIN(WIN_X / 2 / map->width, WIN_Y / 2 / map->height);
	ft_map_scale(map, (!scale) ? 1 : scale);
	ft_map_move(map, WIN_X / 2 - map->center->x, WIN_Y / 2 - map->center->y,
		-(map->z_min + map->z_max) / 2);
	map->center->z = 0;
}
