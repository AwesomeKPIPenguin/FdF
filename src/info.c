/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:36:07 by domelche          #+#    #+#             */
/*   Updated: 2018/02/18 17:51:57 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_draw_square(t_params *p, int b_side, int x, int y)
{
	t_point	*pnt0;
	t_point	*pnt1;
	t_point	*pnt2;
	t_point	*pnt3;

	pnt0 = ft_pointnew(x, y, 0, WHITE);
	pnt1 = ft_pointnew(x + b_side, y, 0, WHITE);
	pnt2 = ft_pointnew(x + b_side, y + b_side, 0, WHITE);
	pnt3 = ft_pointnew(x, y + b_side, 0, WHITE);
	ft_draw_line(p->img, pnt0, pnt1, 0);
	ft_draw_line(p->img, pnt1, pnt2, 0);
	ft_draw_line(p->img, pnt2, pnt3, 0);
	ft_draw_line(p->img, pnt3, pnt0, 0);
	free(pnt0);
	free(pnt1);
	free(pnt2);
	free(pnt3);
}

static void	ft_draw_squares(t_params *p, int b_side)
{
	ft_draw_square(p, b_side, 2 * b_side, b_side);
	ft_draw_square(p, b_side, 2 * b_side, 3 * b_side);
	ft_draw_square(p, b_side, b_side, 4 * b_side);
	ft_draw_square(p, b_side, 2 * b_side, 4 * b_side);
	ft_draw_square(p, b_side, 3 * b_side, 4 * b_side);
	ft_draw_square(p, b_side, b_side, 6 * b_side);
	ft_draw_square(p, b_side, 2 * b_side, 6 * b_side);
	ft_draw_square(p, b_side, 3 * b_side, 6 * b_side);
	ft_draw_square(p, b_side, b_side, 7 * b_side);
	ft_draw_square(p, b_side, 2 * b_side, 7 * b_side);
	ft_draw_square(p, b_side, 3 * b_side, 7 * b_side);
	ft_draw_square(p, b_side, b_side, 9 * b_side);
	ft_draw_square(p, b_side, 3 * b_side, 9 * b_side);
	ft_draw_square(p, b_side, 2 * b_side, 11 * b_side);
	mlx_put_image_to_window(p->mlx, p->win, p->img->ptr, 0, 0);
}

static void	ft_draw_strings(t_params *p, int b_side)
{
	mlx_string_put(p->mlx, p->win, 2.2 * b_side, 1.2 * b_side, WHITE, "Esc");
	mlx_string_put(p->mlx, p->win, 2.4 * b_side, 3.3 * b_side, WHITE, "W");
	mlx_string_put(p->mlx, p->win, 1.4 * b_side, 4.3 * b_side, WHITE, "A");
	mlx_string_put(p->mlx, p->win, 2.4 * b_side, 4.3 * b_side, WHITE, "S");
	mlx_string_put(p->mlx, p->win, 3.4 * b_side, 4.3 * b_side, WHITE, "D");
	mlx_string_put(p->mlx, p->win, 1.4 * b_side, 6.3 * b_side, WHITE, "<");
	mlx_string_put(p->mlx, p->win, 2.4 * b_side, 6.2 * b_side, WHITE, "^");
	mlx_string_put(p->mlx, p->win, 2.4 * b_side, 6.4 * b_side, WHITE, "|");
	mlx_string_put(p->mlx, p->win, 3.4 * b_side, 6.3 * b_side, WHITE, ">");
	mlx_string_put(p->mlx, p->win, 1.4 * b_side, 7.3 * b_side, WHITE, "<-");
	mlx_string_put(p->mlx, p->win, 2.4 * b_side, 7.2 * b_side, WHITE, "|");
	mlx_string_put(p->mlx, p->win, 2.4 * b_side, 7.4 * b_side, WHITE, "v");
	mlx_string_put(p->mlx, p->win, 3.4 * b_side, 7.3 * b_side, WHITE, "->");
	mlx_string_put(p->mlx, p->win, 1.4 * b_side, 9.3 * b_side, WHITE, "+");
	mlx_string_put(p->mlx, p->win, 3.4 * b_side, 9.3 * b_side, WHITE, "-");
	mlx_string_put(p->mlx, p->win, 2.4 * b_side, 11.3 * b_side, WHITE, "C");
	mlx_string_put(p->mlx, p->win, 5 * b_side, 1.2 * b_side, WHITE, " - Exit");
	mlx_string_put(p->mlx, p->win, 5 * b_side, 3.8 * b_side, WHITE,
		" - Movement");
	mlx_string_put(p->mlx, p->win, 5 * b_side, 6.8 * b_side, WHITE,
		" - Rotation");
	mlx_string_put(p->mlx, p->win, 5 * b_side, 9.2 * b_side, WHITE,
		" - Scaling");
	mlx_string_put(p->mlx, p->win, 5 * b_side, 11.2 * b_side, WHITE,
		" - Turn colour on/off");
}

void		ft_info(t_params *p)
{
	int		b_side;

	b_side = 50;
	ft_draw_squares(p, b_side);
	ft_draw_strings(p, b_side);
}
