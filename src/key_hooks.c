/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:18:27 by domelche          #+#    #+#             */
/*   Updated: 2018/03/15 22:02:25 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_movement_hook(int key_code, void *p)
{
	if (key_code == W)
		ft_map_move(((t_params *)p)->map, 0, 50, 0);
	else if (key_code == A)
		ft_map_move(((t_params *)p)->map, 50, 0, 0);
	else if (key_code == S)
		ft_map_move(((t_params *)p)->map, 0, -50, 0);
	else if (key_code == D)
		ft_map_move(((t_params *)p)->map, -50, 0, 0);
}

static void	ft_rotation_hook(int key_code, void *p)
{
	if (key_code == ARR_UP)
		ft_map_rotate(((t_params *)p)->map, PI / 18.0, 0, 0);
	else if (key_code == ARR_DOWN)
		ft_map_rotate(((t_params *)p)->map, PI / -18.0, 0, 0);
	else if (key_code == ARR_RIGHT)
		ft_map_rotate(((t_params *)p)->map, 0, PI / 18.0, 0);
	else if (key_code == ARR_LEFT)
		ft_map_rotate(((t_params *)p)->map, 0, PI / -18.0, 0);
	else if (key_code == ARR_LESS)
		ft_map_rotate(((t_params *)p)->map, 0, 0, PI / -18.0);
	else if (key_code == ARR_MORE)
		ft_map_rotate(((t_params *)p)->map, 0, 0, PI / 18.0);
}

static void	ft_scale_hook(int key_code, void *p)
{
	t_point	*vector;
	t_map	*map;
	int		dif;

	vector = NULL;
	map = ((t_params *)p)->map;
	if (key_code == PLUS || key_code == MINUS)
	{
		dif = (key_code == PLUS) ? 1 : -1;
		dif = (map->scale == 1 && dif == -1) ? 0 : dif;
		if (ft_is_at_center(map))
			vector = ft_pointnew((map->points[0][0]->x - WIN_X / 2) /
				map->scale * (map->scale + dif) -
				(map->points[0][0]->x - WIN_X / 2),
				(map->points[0][0]->y - WIN_Y / 2) /
				map->scale * (map->scale + dif) -
				(map->points[0][0]->y - WIN_Y / 2),
				map->points[0][0]->z / map->scale * (map->scale + dif) -
				map->points[0][0]->z, 0);
		ft_map_scale(map, map->scale + dif);
		if (vector)
			ft_map_move(map, vector->x, vector->y, vector->z);
	}
	if (vector)
		free(vector);
}

int			ft_exit_hook(int key_code, void *p)
{
	(void)p;
	if (key_code == ESC)
		exit(EXIT_SUCCESS);
	return (1);
}

int			ft_key_hook(int key_code, void *p)
{
	ft_exit_hook(key_code, p);
	if (key_code == C)
		((t_params *)p)->map->is_colourful =
			(((t_params *)p)->map->is_colourful) ? 0 : 1;
	ft_movement_hook(key_code, p);
	ft_rotation_hook(key_code, p);
	ft_scale_hook(key_code, p);
	ft_render_map(p);
	return (0);
}
