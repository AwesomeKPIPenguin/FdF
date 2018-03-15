/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:43:06 by domelche          #+#    #+#             */
/*   Updated: 2018/02/18 17:49:57 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_free_rgb(double **rgb)
{
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb[3]);
	free(rgb);
}

static int	ft_is_right_colour(t_map *map, int i, int j)
{
	double	*rgb;
	double	**rgb_side;
	int		ret;

	if (!map->colour_set)
		return (1);
	rgb = ft_colour_to_rgb(map->origin[i][j]->colour);
	rgb_side = (double **)ft_smemalloc(sizeof(double) * 4,
		"ft_is_right_colour");
	rgb_side[0] = ft_colour_to_rgb(map->origin[i - 1][j]->colour);
	rgb_side[1] = ft_colour_to_rgb(map->origin[i][j + 1]->colour);
	rgb_side[2] = ft_colour_to_rgb(map->origin[i + 1][j]->colour);
	rgb_side[3] = ft_colour_to_rgb(map->origin[i][j - 1]->colour);
	ret = 1;
	if (rgb[0] != (rgb_side[3][0] + rgb_side[1][0]) / 2 ||
		rgb[1] != (rgb_side[3][1] + rgb_side[1][1]) / 2 ||
		rgb[2] != (rgb_side[3][2] + rgb_side[1][2]) / 2 ||
		rgb[0] != (rgb_side[0][0] + rgb_side[2][0]) / 2 ||
		rgb[1] != (rgb_side[0][1] + rgb_side[2][1]) / 2 ||
		rgb[2] != (rgb_side[0][2] + rgb_side[2][2]) / 2)
		ret = 0;
	free(rgb);
	ft_free_rgb(rgb_side);
	return (ret);
}

static int	ft_isline(t_map *map, int i, int j)
{
	if (map->origin[i][j]->x != (map->origin[i - 1][j]->x +
			map->origin[i + 1][j]->x) / 2 ||
		map->origin[i][j]->y != (map->origin[i - 1][j]->y +
			map->origin[i + 1][j]->y) / 2 ||
		map->origin[i][j]->z != (map->origin[i - 1][j]->z +
			map->origin[i + 1][j]->z) / 2 ||
		map->origin[i][j]->x != (map->origin[i][j - 1]->x +
			map->origin[i][j + 1]->x) / 2 ||
		map->origin[i][j]->y != (map->origin[i][j - 1]->y +
			map->origin[i][j + 1]->y) / 2 ||
		map->origin[i][j]->z != (map->origin[i][j - 1]->z +
			map->origin[i][j + 1]->z) / 2 ||
		!ft_is_right_colour(map, i, j))
		return (0);
	return (1);
}

static void	ft_remove_points(t_map *map, int *coords)
{
	int		i;

	i = 0;
	while (coords[i])
	{
		free(map->points[coords[i]][coords[i + 1]]);
		free(map->origin[coords[i]][coords[i + 1]]);
		map->points[coords[i]][coords[i + 1]] = NULL;
		map->origin[coords[i]][coords[i + 1]] = NULL;
		i += 2;
	}
	free(coords);
}

void		ft_optimize(t_map *map)
{
	int		i;
	int		j;
	int		k;
	int		*to_remove;

	to_remove = (int *)ft_smemalloc(sizeof(int) *
		((map->width - 2) * (map->height - 2) * 2 + 1), "ft_optimize");
	i = 0;
	k = 0;
	while (++i < (map->height - 1) / map->scale)
	{
		j = 0;
		while (++j < (map->width - 1) / map->scale)
		{
			if (ft_isline(map, i, j))
			{
				to_remove[k++] = i;
				to_remove[k++] = j;
			}
		}
	}
	ft_remove_points(map, to_remove);
}
