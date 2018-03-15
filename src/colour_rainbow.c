/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_rainbow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:03:27 by domelche          #+#    #+#             */
/*   Updated: 2018/02/18 17:36:45 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_return(double *tofree, int res)
{
	free(tofree);
	return (res);
}

int			ft_get_rainbow_index(int colour)
{
	double	*rgb;

	rgb = ft_colour_to_rgb(colour);
	if (rgb[2] > 0)
	{
		if (rgb[1] == 0)
			return (ft_return(rgb, (int)rgb[2] - 128));
		if (rgb[1] < 255)
			return (ft_return(rgb, 127 + (int)rgb[1]));
		else
			return (ft_return(rgb, 127 + 255 + (256 - (int)rgb[2])));
	}
	else
	{
		if (rgb[1] == 255)
			return (ft_return(rgb, 127 + 2 * 255 + (int)rgb[0]));
		if (rgb[1] > 0)
			return (ft_return(rgb, 127 + 3 * 255 + (256 - (int)rgb[1])));
		else
			return (ft_return(rgb, 127 + 4 * 255 + (256 - (int)rgb[0])));
	}
}

int			ft_rainbow(int step)
{
	if (step <= 127)
		return (DARK_BLUE + step);
	if (step <= 127 + 255)
		return (BLUE + ((step - 127) << 8));
	if (step <= 127 + 2 * 255)
		return (GREEN_BLUE - (step - 127 - 255));
	if (step <= 127 + 3 * 255)
		return (GREEN + ((step - 127 - 2 * 255) << 16));
	if (step <= 127 + 4 * 255)
		return (RED_GREEN - ((step - 127 - 3 * 255) << 8));
	else
		return (RED - ((step - 127 - 4 * 255) << 16));
}
