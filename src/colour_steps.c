/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_steps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:01:56 by domelche          #+#    #+#             */
/*   Updated: 2018/03/07 17:27:31 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	*ft_get_c_steps(int colour1, int colour2, int i)
{
	double	*steps;
	double	tmp;

	steps = (double *)ft_smemalloc(sizeof(double) * 3, "ft_get_c_steps");
	steps[2] = (double)((modf(colour2 / pow(16, 2), &tmp) * pow(16, 2) -
		modf(colour1 / pow(16, 2), &tmp) * pow(16, 2)) / (double)i);
	steps[1] = (double)(((int)(modf(colour2 / pow(16, 4), &tmp) * pow(16, 2)) -
		(int)(modf(colour1 / pow(16, 4), &tmp) * pow(16, 2))) / (double)i);
	steps[0] = (double)(((int)(colour2 / pow(16, 4)) -
		(int)(colour1 / pow(16, 4))) / (double)i);
	return (steps);
}

void	ft_make_step(double *arg, double *rgb, double *c_steps)
{
	arg[0] += arg[3];
	arg[1] += arg[4];
	arg[2] += arg[5];
	rgb[0] += c_steps[0];
	rgb[1] += c_steps[1];
	rgb[2] += c_steps[2];
}
