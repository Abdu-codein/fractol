/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 22:56:15 by amardini          #+#    #+#             */
/*   Updated: 2026/06/07 18:24:41 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot_design(char **argv, t_fractal *data)
{
	double ratio;

	(void)argv;
	ratio = (double)DIM_Z / (double)DIM_Y;
	data->whatis = 1;
	data->max_real = -2 + (2.6 * ratio);
	data->min_real = -2;
	data->max_imaginary = 1.3;
	data->min_imaginary = -1.3;
}
int mandel_cal(double coor_x, double coor_y, t_fractal *info)
{
	int i;
	double zr;
	double zi;
	double tmp;

	zr = 0;
	zi = 0;
	i = 0;
	while (info->max_iteration > i)
	{
		if ((zr * zr) + (zi * zi) > 4.0)
			break;
		tmp = (zr * zr) - (zi * zi) + coor_x;
		zi = 2 * zr * zi + coor_y;
		zr = tmp;
		i++;
	}
	return (i);
}
