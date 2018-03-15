/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:58:03 by domelche          #+#    #+#             */
/*   Updated: 2018/02/16 17:33:58 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_move_point(t_map *map, t_point *opoint, t_point *point)
{
	if (!point)
		return ;
	point->x += map->move_vector->x;
	point->y += map->move_vector->y;
	point->z += map->move_vector->z;
	opoint->x += map->move_vector->x;
	opoint->y += map->move_vector->y;
	opoint->z += map->move_vector->z;
}

void		ft_map_move(t_map *map, int x, int y, int z)
{
	map->move_vector->x = x;
	map->move_vector->y = y;
	map->move_vector->z = z;
	map->center->x += x;
	map->center->y += y;
	map->center->z += z;
	map->z_min += z;
	map->z_max += z;
	ft_foreach_point(map, ft_move_point, 2);
	map->move_vector->x = 0;
	map->move_vector->y = 0;
	map->move_vector->z = 0;
}
