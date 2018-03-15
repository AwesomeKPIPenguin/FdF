/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:35:03 by domelche          #+#    #+#             */
/*   Updated: 2018/02/18 20:38:07 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_usage(void)
{
	ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	ft_putendl("        ./fdf info - get manipulation settings");
	return (1);
}

void		ft_error(char *msg)
{
	ft_putstr("Error: ");
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_params	*params;

	if (ac != 2)
		return (ft_usage());
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_X, WIN_Y, "FdF - domelche");
	img = ft_imgnew(mlx, WIN_X, WIN_Y);
	map = (ft_strcmp("info", av[1])) ? ft_getmap(av[1]) : ft_mapnew(0, 0);
	params = ft_paramsnew(mlx, win, img, map);
	if (ft_strcmp("info", av[1]))
	{
		ft_render_map(params);
		mlx_key_hook(win, ft_key_hook, (void *)params);
	}
	else
	{
		ft_info(params);
		mlx_key_hook(win, ft_exit_hook, (void *)params);
	}
	mlx_loop(mlx);
	return (0);
}
