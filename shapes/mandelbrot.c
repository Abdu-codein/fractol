/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 22:56:15 by amardini          #+#    #+#             */
/*   Updated: 2026/06/05 23:03:46 by amardini         ###   ########.fr       */
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
int mandel_cal(double coor_x, double coor_y)
{
    
}

z = z^2 + c


X.n+1 = -rx^2.n + rx.n = (r * x.n) - (r * x^2.n) = (r * x.n) * (1 - x.n)