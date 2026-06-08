/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 17:50:10 by amardini          #+#    #+#             */
/*   Updated: 2026/06/08 15:13:41 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	calculating(t_fractal *info, int d, double x_real, double y_imag)
{
	if (d == 65363)
	{
		info->min_real = info->min_real + x_real;
		info->max_real = info->max_real + x_real;
	}
	else if (d == 65361)
	{
		info->min_real = info->min_real - x_real;
		info->max_real = info->max_real - x_real;
	}
	else if (d == 65362)
	{
		info->min_imaginary = info->min_imaginary + y_imag;
		info->max_imaginary = info->max_imaginary + y_imag;
	}
	else if (d == 65364)
	{
		info->min_imaginary = info->min_imaginary - y_imag;
		info->max_imaginary = info->max_imaginary - y_imag;
	}
}

static void	move(t_fractal *info, int direction)
{
	double	width;
	double	length;
	double	x_real;
	double	y_imag;

	width = info->max_real - info->min_real;
	length = info->max_imaginary - info->min_imaginary;
	x_real = width * 0.05;
	y_imag = length * 0.05;
	calculating(info, direction, x_real, y_imag);
}

int	handle_mouse(int input, int x, int y, void *param)
{
	t_fractal	*info;

	info = (t_fractal *)param;
	if (input == 1)
		info->max_iteration = info->max_iteration + 5;
	else if (input == 3)
		info->max_iteration = info->max_iteration - 5;
	if (input == 5)
		zoom_m(info, ZOOM_IN, x, y);
	if (input == 4)
		zoom_m(info, ZOOM_OUT, x, y);
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
		zoom_k(info, ZOOM_IN);
	else if (input == 120)
		zoom_k(info, ZOOM_OUT);
	else if (input == 114)
		info->colour = 2;
	else if (input == 103)
		info->colour = 3;
	else if (input == 98)
		info->colour = 4;
	else if (input == 112)
		info->colour = 1;
	else if (input == 65307)
		distruc_error(info, 123, 'z');
	create_shape(info);
	return (0);
}
