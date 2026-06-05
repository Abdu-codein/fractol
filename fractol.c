/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:47:26 by amardini          #+#    #+#             */
/*   Updated: 2026/06/05 22:56:47 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int main(int argc, char **argv)
{
	t_fractal p;
	user_input(argc, argv, &p);
	window_create(&p);
	create_shape(&p);
	//BONUS keyboard moving
	// BONUS mouse tracking
	//closing the application by X or ESC
	mlx_loop(p.mlx);
	return (0);
}
