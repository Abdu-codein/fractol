/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 17:50:10 by amardini          #+#    #+#             */
/*   Updated: 2026/06/08 04:39:52 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculating(t_fractal *info, int d, double x_real, double y_imag)
{
	if (d == 65363)
	{
		data->min_real = data->min_real + x_real;
		data->max_real = data->max_real + x_real;
	}
	else if (d == 65361)
	{
		data->min_real = data->min_real - x_real;
		data->max_real = data->max_real - x_real;
	}
	else if (d == 65362)
	{
		data->min_imaginary = data->min_imaginary + y_imag;
		data->max_imaginary = data->max_imaginary + y_imag;
	}
	else if (d == 65364)
	{
		data->min_imaginary = data->min_imaginary - y_imag;
		data->max_imaginary = data->max_imaginary - y_imag;
	}
}

static void	move(t_fractal *info, int direction)
{
	double	width;
	double	length;
	double	x_real;
	double	y_imag;

	width = info->max_real - info->min_real;
	length = info->max_imag - info->min_imag;
	x_real = width * 0.05;
	y_imag = length * 0.05;
	calculating(info, direction, x_real, y_imag);
}

static void	zoom(t_fractal *info, double zoom, int device)
{
	double	center_re;
	double	center_im;

	if (device == 1)
	{
		center_re = (info->min_real + info->max_real) / 2;
		center_im = (info->min_imaginary + info->max_imaginary) / 2;
	}
	else
	{
		center_re = info->min_real + (double)x
			* ((info->max_real - info->min_real) / DIM_Z);
		center_im = info->max_imaginary - (double)y
			* ((info->max_imaginary - info->min_imaginary) / DIM_Y);
	}
	info->min_real = center_re + (info->min_real - center_re) * zoom;
	info->max_real = center_re + (info->max_real - center_re) * zoom;
	info->min_imaginary = center_im + (info->min_imaginary - center_im) * zoom;
	info->max_imaginary = center_im + (info->max_imaginary - center_im) * zoom;
}

int	handle_mouse(int input, void *param)
{
	t_fractal	*info;
	double		mouse_x;
	double		mouse_y;

	info = (t_fractal *)param;
	if (input == 1)
		info->max_iteration = info->max_iteration + 5;
	else if (input == 2)
		info->max_iteration = info->max_iteration - 5;
	if (input == 4)
		zoom (info, ZOOM_IN, 2);
	if (input == 5)
		zoom (info, ZOOM_OUT, 2);
	create_shape(info);
	return (0);
}

int	handle_keys(int input, void *param)
{
	t_fractal	*info;

	info = (t_fractal *)param;
	if (input >= 65361 && input <= 65364)
		move(info, input);
	else if (input == 61 || input == 65451)
		info->max_iteration = info->max_iteration + 5;
	else if (input == 45 || input == 65453)
		info->max_iteration = info->max_iteration - 5;
	else if (input == 122)
		zoom (param, ZOOM_IN, 1);
	else if (input == 114)
		zoom (param, ZOOM_OUT, 1);
	else if (input == 114)
		info->colour = 2;
	else if (input == 103)
		info->colour = 3;
	else if (input == 98)
		info->colour = 4;
	else if (input == 112)
		info->colour = 1;
	else if (input == 65307)
		distruct_error(info, 123, z);
	create_shape(info);
	return (0);
}
