/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:42:18 by domelche          #+#    #+#             */
/*   Updated: 2018/02/18 17:52:41 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static double	*ft_get_sin(t_map *map)
{
	double	*sin_ptr;

	sin_ptr = (double *)ft_smemalloc(sizeof(double) * 3, "ft_get_sin");
	sin_ptr[0] = sin(map->rotation_angles[0]);
	sin_ptr[1] = sin(map->rotation_angles[1]);
	sin_ptr[2] = sin(map->rotation_angles[2]);
	return (sin_ptr);
}

static double	*ft_get_cos(t_map *map)
{
	double	*cos_ptr;

	cos_ptr = (double *)ft_smemalloc(sizeof(double) * 3, "ft_get_cos");
	cos_ptr[0] = cos(map->rotation_angles[0]);
	cos_ptr[1] = cos(map->rotation_angles[1]);
	cos_ptr[2] = cos(map->rotation_angles[2]);
	return (cos_ptr);
}

static void		ft_rotate_point(t_map *map, t_point *opoint, t_point *point)
{
	double	*sin_ptr;
	double	*cos_ptr;

	if (!point)
		return ;
	sin_ptr = ft_get_sin(map);
	cos_ptr = ft_get_cos(map);
	point->x = (opoint->x - map->center->x) * cos_ptr[2] * cos_ptr[1] +
		(opoint->y - map->center->y) *
		(cos_ptr[2] * sin_ptr[1] * sin_ptr[0] - sin_ptr[2] * cos_ptr[0]) +
		(opoint->z - map->center->z) *
		(sin_ptr[2] * sin_ptr[0] + cos_ptr[0] * cos_ptr[2] * sin_ptr[1]) +
		map->center->x;
	point->y = (opoint->x - map->center->x) * cos_ptr[1] * sin_ptr[2] +
		(opoint->y - map->center->y) *
		(cos_ptr[0] * cos_ptr[2] + sin_ptr[0] * sin_ptr[1] * sin_ptr[2]) +
		(opoint->z - map->center->z) *
		(cos_ptr[0] * sin_ptr[1] * sin_ptr[2] - sin_ptr[0] * cos_ptr[2]) +
		map->center->y;
	point->z = (opoint->x - map->center->x) * -(sin_ptr[1]) +
		(opoint->y - map->center->y) * sin_ptr[0] * cos_ptr[1] +
		(opoint->z - map->center->z) * cos_ptr[0] * cos_ptr[1] + map->center->z;
	free(sin_ptr);
	free(cos_ptr);
}

void			ft_map_rotate(t_map *map, double alpha, double beta,
					double gamma)
{
	map->rotation_angles[0] += alpha;
	map->rotation_angles[1] += beta;
	map->rotation_angles[2] += gamma;
	ft_foreach_point(map, ft_rotate_point, 2);
}
