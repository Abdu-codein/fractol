/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 17:50:10 by amardini          #+#    #+#             */
/*   Updated: 2026/06/07 18:42:16 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom (t_fractal *info, double zoom)
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

int	handle_mouse(int input, void *param)
{
	t_fractal *info;

	info = (t_fractal *)param;
	if (input == 1)
		info->max_iteration = info->max_iteration + 5;
	else if (input == 2)
		info->max_iteration = info->max_iteration - 5;
	else if (input == 4)
		zoom (param, 1.2);
	else if (input == 4)
		zoom (param, 0.8);
	create_shape(info);
}

int	handle_keys(int input, void *param)
{
	t_fractal *info;

	info = (t_fractal *)param;
	if (input == 65364) //DOWN
	{
		
	}
	else if (input == 65362) //UP
	{
		
	}
	else if (input == 65363) //RIHGHT
	{
		
	}
	else if (input == 65361) //LEFT
	{
		
	}
	else if (input == 61 || input == 65451) //plus
	{
		
	}
	else if (input == 45 || input == 65453) //minus





	else if (input == 65307) //ESC

}

int	handle_close(void *param)
{
	t_fractal *info;

	info = (t_fractal *)param;
}

//closing needs the code still (to close)
//mouse is done
//keyboard needs the coding aspect, and needs r(red) g(green) b(blue) p(psychedelic)