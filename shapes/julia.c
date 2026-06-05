/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 22:56:11 by amardini          #+#    #+#             */
/*   Updated: 2026/06/05 22:49:50 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia_design(char **argv, t_fractal *data)
{
    double ratio;
    double real;
    double imag;

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

int julia_cal(double coor_x, double coor_y, double input_x, double input_y)
{
    
}