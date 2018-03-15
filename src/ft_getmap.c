/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:17:48 by domelche          #+#    #+#             */
/*   Updated: 2018/03/07 17:04:28 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_get_mapsize(char *file, int fd, int *width, int *height)
{
	char	**tab;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error("can not open file");
	if (read(fd, NULL, 0) == -1)
		ft_error("target is unable to read");
	if (!get_next_line(fd, &line))
		ft_error("file is empty");
	tab = ft_strsplit(line, ' ');
	if (!(*width = ft_arrlen(tab)))
		ft_error("invalid map");
	ft_free_tab(tab);
	free(line);
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		if (ft_arrlen(tab) != *width)
			ft_error("invalid map");
		++(*height);
		free(line);
		ft_free_tab(tab);
	}
	free(line);
	close(fd);
}

static void	ft_fill_mapline(t_map *map, char *line, int line_count)
{
	char	**tab;
	int		i;
	t_point	*point;

	tab = ft_strsplit(line, ' ');
	i = -1;
	while (tab[++i])
	{
		map->points[line_count][i] =
			ft_pointnew(i * map->scale, line_count * map->scale,
				ft_atoi(tab[i]) * map->scale, ft_get_colour(tab[i]));
		point = map->points[line_count][i];
		map->origin[line_count][i] =
			ft_pointnew(point->x, point->y, point->z, point->colour);
		if (map->points[line_count][i]->colour != WHITE)
			map->colour_set = 1;
	}
	ft_free_tab(tab);
}

static void	ft_get_zminmax(t_map *map, t_point *point)
{
	if (point->z < map->z_min)
		map->z_min = point->z;
	if (point->z > map->z_max)
		map->z_max = point->z;
}

t_map		*ft_getmap(char *file)
{
	int		fd;
	char	*line;
	int		size[2];
	int		line_count;
	t_map	*map;

	size[1] = 1;
	ft_get_mapsize(file, 0, &(size[0]), &(size[1]));
	fd = open(file, O_RDONLY);
	map = ft_mapnew(size[0], size[1]);
	line_count = -1;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_fill_mapline(map, line, ++line_count);
		free(line);
	}
	free(line);
	close(fd);
	ft_foreach_point(map, ft_get_zminmax, 0);
	map->center->z = (map->z_max - map->z_min) / 2;
	ft_dist_colours(map);
	ft_normalize_map(map);
	ft_optimize(map);
	return (map);
}
