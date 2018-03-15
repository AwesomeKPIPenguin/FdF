/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:42:58 by domelche          #+#    #+#             */
/*   Updated: 2018/02/15 18:34:24 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_params	*ft_paramsnew(void *mlx, void *win, t_img *img, t_map *map)
{
	t_params	*params;

	params = (t_params *)ft_smemalloc(sizeof(t_params), "ft_paramsnew");
	params->mlx = mlx;
	params->win = win;
	params->img = img;
	params->map = map;
	return (params);
}
