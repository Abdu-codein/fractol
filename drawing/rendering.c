/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 21:28:48 by amardini          #+#    #+#             */
/*   Updated: 2026/06/05 22:54:23 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_shape(t_fractal *info)
{
	unsigned int x;
	unsigned int y;
	double	coord_x;
	double	coord_y;
	int	iter;

	y = 0;
	while (y < DIM_Y)
	{
		x = 0;
		while (x < DIM_Z)
		{
			coord_x = info->min_real + (double)x / DIM_Z * (info->max_real - info->min_real);
			coord_y = info->min_imaginary + (double)y / DIM_Y * (info->max_imaginary - info->min_imaginary);
			if (info->whatis == 1)
				iter = mandel_cal(coord_x, coord_y);
			else if (info->whatis == 2)
				iter = julia_cal(coord_x, coord_y, info->julia_real, info->julia_imaginary)
			draw
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}