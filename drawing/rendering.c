/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 21:28:48 by amardini          #+#    #+#             */
/*   Updated: 2026/06/08 15:49:15 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	shape_set(t_fractal *info, int x, int y)
{
	double	coord_x;
	double	coord_y;
	int		iter;

	coord_x = info->min_real + (double)x / DIM_Z
		* (info->max_real - info->min_real);
	coord_y = info->max_imaginary - (double)y / DIM_Y
		* (info->max_imaginary - info->min_imaginary);
	if (info->whatis == 1)
		iter = mandel_cal(coord_x, coord_y, info);
	else if (info->whatis == 2)
		iter = julia_cal(coord_x, coord_y, info);
	else if (info->whatis == 3)
		iter = ship_cal(coord_x, coord_y, info);
	return (iter);
}

static void	pixel_draw(t_fractal *info, int x, int y, int colour)
{
	char	*dst;

	dst = info->addr + (y * info->line_len + x * (info->bpp / 8));
	*(unsigned int *)dst = colour;
}

static void	colour_set(t_fractal *info, int x, int y, int iter)
{
	if (info->colour == 1)
		pixel_draw(info, x, y, dynamic_colour(iter, info));
	if (info->colour == 2)
		pixel_draw(info, x, y, single_colour(iter, 2, info));
	if (info->colour == 3)
		pixel_draw(info, x, y, single_colour(iter, 3, info));
	if (info->colour == 4)
		pixel_draw(info, x, y, single_colour(iter, 4, info));
}

void	create_shape(t_fractal *info)
{
	int	x;
	int	y;
	int	iter;

	y = 0;
	while (y < DIM_Y)
	{
		x = 0;
		while (x < DIM_Z)
		{
			iter = shape_set(info, x, y);
			colour_set(info, x, y, iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}
