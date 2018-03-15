/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:16:58 by domelche          #+#    #+#             */
/*   Updated: 2018/02/18 17:51:02 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_map_init(t_map *map, int width, int height)
{
	map->width = width;
	map->height = height;
	map->colour_set = 0;
	map->is_colourful = 1;
	map->scale = 1;
	map->rotation_angles[0] = 0;
	map->rotation_angles[1] = 0;
	map->rotation_angles[2] = 0;
	map->center = ft_pointnew(map->width / 2, map->height / 2, 0, 0);
	map->move_vector = ft_pointnew(0, 0, 0, 0);
}

static int	ft_memalloc_points(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->height)
		if (!(map->points[i] =
			(t_point **)ft_memalloc(sizeof(t_point *) * map->width)) ||
				!(map->origin[i] =
					(t_point **)ft_memalloc(sizeof(t_point *) * map->width)))
		{
			while (--i >= 0)
			{
				free(map->points[i]);
				free(map->origin[i]);
			}
			free(map->points);
			free(map->origin);
			free(map->center);
			free(map);
			return (0);
		}
	return (1);
}

t_map		*ft_mapnew(int width, int height)
{
	t_map	*map;

	map = (t_map *)ft_smemalloc(sizeof(t_map), "ft_mapnew");
	ft_map_init(map, width, height);
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	if (!(map->points =
		(t_point ***)ft_memalloc(sizeof(t_point **) * height)) ||
		!(map->origin = (t_point ***)ft_memalloc(sizeof(t_point **) * height)))
	{
		free(map);
		ft_error("memory allocation for map points failed");
	}
	if (!ft_memalloc_points(map))
		ft_error("memory allocation at ft_memalloc_points failed");
	return (map);
}
