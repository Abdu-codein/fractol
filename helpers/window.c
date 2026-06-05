/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 20:24:30 by amardini          #+#    #+#             */
/*   Updated: 2026/06/05 21:05:53 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_create(t_fractal *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		write (1, "MLX faced an issue while creating connection, try again!\n", 57);
	info->win = mlx_new_window(info->mlx, DIM_Z, DIM_Y, "Fractol");
	if (!info->win)
		distruc_error(&info, 1, 'a');
	info->img = mlx_new_image(info->mlx, DIM_Z, DIM_Y);
	if (!info->img)
		distruc_error(&info, 12, 'b');
	info->addr = mlx_get_data_addr(info->mlx, &info->bpp, &info->line_len, &info->endian);
	if (!info->addr)
		distruc_error(&info, 123, 'c');
}