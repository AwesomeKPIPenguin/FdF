/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:25:01 by domelche          #+#    #+#             */
/*   Updated: 2018/02/18 17:48:52 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	*ft_colour_to_rgb(unsigned int colour)
{
	double	*rgb;

	rgb = (double *)ft_smemalloc(sizeof(double) * 3, "ft_colour_to_rgb");
	rgb[2] = colour << 24 >> 24;
	rgb[1] = colour << 16 >> 24;
	rgb[0] = colour >> 16;
	return (rgb);
}

int		ft_rgb_to_colour(double *rgb)
{
	return (((unsigned int)rgb[0] << 16) +
			((unsigned int)rgb[1] << 8) + (unsigned int)rgb[2]);
}

int		ft_get_colour(char *str)
{
	int		colour;
	int		i;
	int		j;

	i = 0;
	colour = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (!str[i])
		return (WHITE);
	if (str[i + 1] == '0' && ft_toupper(str[i + 2]) == 'X')
		i += 2;
	j = -1;
	while (str[++i] && ++j < 6)
	{
		str[i] = ft_toupper(str[i]);
		if (!ft_isdigit(str[i]) && (str[i] < 'A' || str[i] > 'F'))
			break ;
		colour = (colour << 4) + ((ft_isdigit(str[i]))
				? str[i] - '0' : str[i] - 'A' + 10);
	}
	return (colour);
}

void	ft_dist_colours(t_map *map)
{
	double	step;
	int		j;
	int		i;

	if (map->colour_set)
		return ;
	step = (map->z_max == map->z_min) ? 0 :
		RAINBOW_DIF / (double)(map->z_max - map->z_min);
	i = -1;
	while (++i < map->height / map->scale)
	{
		j = -1;
		while (++j < map->width / map->scale)
			map->points[i][j]->colour = (!step) ? GREEN :
				ft_rainbow((double)(map->points[i][j]->z - map->z_min) * step);
	}
}
