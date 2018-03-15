/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:06:36 by domelche          #+#    #+#             */
/*   Updated: 2018/02/18 15:22:58 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_is_at_center(t_map *map)
{
	if (WIN_X / 2 > map->points[0][0]->x &&
		WIN_X / 2 < map->points[map->height / map->scale - 1]
		[map->width / map->scale - 1]->x &&
		WIN_Y / 2 > map->points[0][0]->y &&
		WIN_Y / 2 < map->points[map->height / map->scale - 1]
		[map->width / map->scale - 1]->y)
		return (1);
	return (0);
}

static void	ft_unscale(t_map *map, t_point *opoint)
{
	if (!opoint)
		return ;
	opoint->x /= map->scale;
	opoint->y /= map->scale;
	opoint->z /= map->scale;
}

static void	ft_unscale_map(t_map *map)
{
	ft_foreach_point(map, ft_unscale, 0);
	map->width /= map->scale;
	map->height /= map->scale;
	map->z_min /= map->scale;
	map->z_max /= map->scale;
	map->center->x /= map->scale;
	map->center->y /= map->scale;
	map->center->z /= map->scale;
}

static void	ft_scale(t_map *map, t_point *opoint)
{
	if (!opoint)
		return ;
	opoint->x *= map->scale;
	opoint->y *= map->scale;
	opoint->z *= map->scale;
}

void		ft_map_scale(t_map *map, int scale)
{
	t_point	*point;

	point = ft_point_clone(map->points[0][0]);
	ft_map_move(map, -map->origin[0][0]->x, -map->origin[0][0]->y,
		-map->origin[0][0]->z);
	ft_unscale_map(map);
	map->scale = scale;
	map->width *= map->scale;
	map->height *= map->scale;
	map->z_min *= map->scale;
	map->z_max *= map->scale;
	ft_foreach_point(map, ft_scale, 0);
	map->center->x *= map->scale;
	map->center->y *= map->scale;
	map->center->z *= map->scale;
	ft_map_rotate(map, 0, 0, 0);
	ft_map_move(map, point->x - map->points[0][0]->x,
		point->y - map->points[0][0]->y, point->z - map->points[0][0]->z);
	free(point);
}
