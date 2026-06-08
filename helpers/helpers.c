/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:56:41 by amardini          #+#    #+#             */
/*   Updated: 2026/06/08 15:20:41 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	atod(char *number)
{
	int		i;
	int		sign;
	double	result;
	double	after;

	sign = 1;
	i = 0;
	after = 1;
	result = 0;
	if (number[i] == '-')
		sign = sign * -1;
	if (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i] >= '0' && number[i] <= '9')
		result = result * 10 + (number[i++] - '0');
	if (number[i] == '.')
		i++;
	while (number[i] >= '0' && number[i] <= '9')
	{
		after = after / 10;
		result = result + (number[i++] - '0') * after;
	}
	return (sign * result);
}

void	zoom_k(t_fractal *info, double zoom)
{
	double	center_re;
	double	center_im;

	center_re = (info->min_real + info->max_real) / 2;
	center_im = (info->min_imaginary + info->max_imaginary) / 2;
	info->min_real = center_re + (info->min_real - center_re) * zoom;
	info->max_real = center_re + (info->max_real - center_re) * zoom;
	info->min_imaginary = center_im + (info->min_imaginary - center_im) * zoom;
	info->max_imaginary = center_im + (info->max_imaginary - center_im) * zoom;
}

void	zoom_m(t_fractal *info, double zoom, int x, int y)
{
	double	center_re;
	double	center_im;

	center_re = info->min_real + (double)x
		* ((info->max_real - info->min_real) / DIM_Z);
	center_im = info->max_imaginary - (double)y
		* ((info->max_imaginary - info->min_imaginary) / DIM_Y);
	info->min_real = center_re + (info->min_real - center_re) * zoom;
	info->max_real = center_re + (info->max_real - center_re) * zoom;
	info->min_imaginary = center_im + (info->min_imaginary - center_im) * zoom;
	info->max_imaginary = center_im + (info->max_imaginary - center_im) * zoom;
}
