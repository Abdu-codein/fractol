/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 22:56:11 by amardini          #+#    #+#             */
/*   Updated: 2026/06/08 15:24:47 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia_design(char **argv, t_fractal *data)
{
	double	ratio;
	double	real;
	double	imag;

	real = atod(argv[2]);
	imag = atod(argv[3]);
	if (real < -2.0 || real > 2.0 || imag < -2.0 || imag > 2.0)
		nu_error();
	ratio = (double)DIM_Z / (double)DIM_Y;
	data->whatis = 2;
	data->max_real = (ratio * 4) / 2;
	data->min_real = -((ratio * 4) / 2);
	data->max_imaginary = 2;
	data->min_imaginary = -2;
	data->julia_imaginary = imag;
	data->julia_real = real;
}

int	julia_cal(double coor_x, double coor_y, t_fractal *info)
{
	int		i;
	double	zr;
	double	zi;
	double	tmp;

	zr = coor_x;
	zi = coor_y;
	i = 0;
	while (info->max_iteration > i)
	{
		if ((zr * zr) + (zi * zi) > 4.0)
			break ;
		tmp = (zr * zr) - (zi * zi) + info->julia_real;
		zi = 2 * zr * zi + info->julia_imaginary;
		zr = tmp;
		i++;
	}
	return (i);
}
