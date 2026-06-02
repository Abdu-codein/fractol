/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:58:27 by amardini          #+#    #+#             */
/*   Updated: 2026/06/02 23:28:53 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	m_error(void)
{
	write(1, "==Input not as required==\n", 27);
	write(1, "For Mandelbrot, Input \"mandelbrot\"\n", 35);
	write(1, "For Julia, input \" \"julia\", X_pointer, Y_pointer \" that is between X to X\n", 74);
	exit(1);
}