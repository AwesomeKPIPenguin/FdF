/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:10:24 by domelche          #+#    #+#             */
/*   Updated: 2018/02/15 22:37:45 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_img	*ft_imgnew(void *mlx, int width, int height)
{
	t_img	*img;
	int		i;

	img = (t_img *)ft_smemalloc(sizeof(t_img), "ft_imgnew [for img]");
	img->width = width;
	img->height = height;
	img->ptr = mlx_new_image(mlx, width, height);
	img->data = mlx_get_data_addr(img->ptr, &(img->bpp),
		&(img->size_line), &(img->endian));
	img->bpp /= 8;
	img->z_data = (int *)ft_smemalloc(sizeof(int) * width * height,
		"ft_imgnew [for img->z_data]");
	i = -1;
	while (++i < width * height)
		img->z_data[i] = INT_MIN;
	return (img);
}

void	ft_clear_img(t_img *img)
{
	int		i;

	ft_bzero((void *)img->data, img->bpp * img->width * img->height);
	i = -1;
	while (++i < img->width * img->height)
		img->z_data[i] = INT_MIN;
}
