/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:21:35 by domelche          #+#    #+#             */
/*   Updated: 2018/03/15 21:59:23 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		ft_pixel_put_image(t_img *img, t_point *point, int is_colourful)
{
	if (point->x < 0 || point->x >= WIN_X || point->y < 0 || point->y >= WIN_Y)
		return ;
	if (point->z >= img->z_data[point->y * img->width + point->x])
	{
		*(int *)(img->data + (point->y * img->width + point->x) * img->bpp) =
			(is_colourful) ? point->colour : WHITE;
		img->z_data[point->y * img->width + point->x] = point->z;
	}
}

/*
**	In ft_draw_line(_rnbw):
**
**	arg[0] = current x;
**	arg[1] = current y;
**	arg[2] = current z;
**	arg[3] = x step;
**	arg[4] = y step;
**	arg[5] = z step;
**	arg[6] = max value of x and y steps;
*/

static double	*ft_get_arg(t_point *point1, t_point *point2)
{
	double	*arg;

	if ((point1->x < 0 && point2->x < 0) ||
		(point1->x >= WIN_X && point2->x >= WIN_X) ||
		(point1->y < 0 && point2->y < 0) ||
		(point1->y >= WIN_Y && point2->y >= WIN_Y))
		return (NULL);
	arg = (double *)ft_smemalloc(sizeof(double) * 7, "ft_get_arg");
	arg[0] = point1->x;
	arg[1] = point1->y;
	arg[2] = point1->z;
	arg[3] = point2->x - point1->x;
	arg[4] = point2->y - point1->y;
	arg[5] = point2->z - point1->z;
	arg[6] = MAX((int)fabs(arg[3]), (int)fabs(arg[4]));
	arg[3] /= arg[6];
	arg[4] /= arg[6];
	arg[5] /= arg[6];
	return (arg);
}

void			ft_draw_line(t_img *img, t_point *point1, t_point *point2,
					int is_colourful)
{
	double	*arg;
	t_point	*point;
	double	*rgb;
	double	*c_steps;

	point = ft_pointnew(point1->x, point1->y, point1->z, point1->colour);
	if (!(arg = ft_get_arg(point1, point2)))
		return (free(point));
	c_steps = ft_get_c_steps(point1->colour, point2->colour, arg[6]);
	rgb = ft_colour_to_rgb((unsigned int)point1->colour);
	while (arg[6]-- >= 0)
	{
		point->x = (int)arg[0];
		point->y = (int)arg[1];
		point->z = (int)arg[2];
		point->colour = ft_rgb_to_colour(rgb);
		ft_pixel_put_image(img, point, is_colourful);
		ft_make_step(arg, rgb, c_steps);
	}
	free(rgb);
	free(arg);
	free(c_steps);
	free(point);
}

void			ft_draw_line_rnbw(t_img *img, t_point *point1, t_point *point2,
					int is_colourful)
{
	double	*arg;
	t_point	*point;
	double	colour_i;
	double	colour_step;

	point = ft_pointnew(point1->x, point1->y, point1->z, point1->colour);
	if (!(arg = ft_get_arg(point1, point2)))
		return ;
	colour_i = ft_get_rainbow_index(point1->colour);
	colour_step = (double)(ft_get_rainbow_index(point2->colour) - colour_i)
		/ arg[6];
	while (arg[6]-- >= 0)
	{
		point->x = (int)arg[0];
		point->y = (int)arg[1];
		point->z = (int)arg[2];
		point->colour = ft_rainbow((int)colour_i);
		ft_pixel_put_image(img, point, is_colourful);
		arg[0] += arg[3];
		arg[1] += arg[4];
		arg[2] += arg[5];
		colour_i += colour_step;
	}
	free(arg);
	free(point);
}
