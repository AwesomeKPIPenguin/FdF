/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:53:57 by domelche          #+#    #+#             */
/*   Updated: 2018/02/18 17:52:56 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point		*ft_pointnew(int x, int y, int z, int colour)
{
	t_point		*point;

	point = (t_point *)ft_smemalloc(sizeof(t_point), "ft_pointnew");
	point->x = x;
	point->y = y;
	point->z = z;
	point->colour = colour;
	return (point);
}

t_point		*ft_point_clone(t_point *point)
{
	return (ft_pointnew(point->x, point->y, point->z, point->colour));
}

void		ft_foreach_point(t_map *map, void (*ft)(), int mode)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->height / map->scale)
	{
		j = -1;
		while (++j < map->width / map->scale)
		{
			if (!mode)
				ft(map, map->origin[i][j]);
			else if (mode == 1)
				ft(map, map->points[i][j]);
			else
				ft(map, map->origin[i][j], map->points[i][j]);
		}
	}
}
