/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:47:26 by amardini          #+#    #+#             */
/*   Updated: 2026/06/08 14:47:48 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	handle_close(void *param)
{
	t_fractal	*info;

	info = (t_fractal *)param;
	distruc_error(info, 123, 'z');
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	p;

	user_input(argc, argv, &p);
	window_create(&p);
	p.max_iteration = 50;
	p.colour = 1;
	create_shape(&p);
	mlx_key_hook(p.win, handle_keys, &p);
	mlx_mouse_hook(p.win, handle_mouse, &p);
	mlx_hook(p.win, 17, 0, handle_close, &p);
	mlx_loop(p.mlx);
	return (0);
}
