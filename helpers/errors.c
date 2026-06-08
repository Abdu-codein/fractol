/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:58:27 by amardini          #+#    #+#             */
/*   Updated: 2026/06/08 21:05:07 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	m_error(void)
{
	write(1, "==Input not as required==\n", 27);
	write(1, "For Mandelbrot, Input \"mandelbrot\"\n\n", 36);
	write(1, "For Julia, input \" \"julia\", X_pointer, Y_pointer \"", 50);
	write(1, "Input should be between -2.0 to 2.0\n\n", 37);
	write(1, "For Burning ship, Input \"Burning ship\"\n\n", 40);
	exit(1);
}

void	nu_error(void)
{
	write(1, "Input should stricly be between -2.0 to 2.0\n", 44);
	write(1, "         Try again         \n", 28);
	exit(1);
}

void	distruc_error(t_fractal *info, int errors, char issue)
{
	if (errors == 123)
		mlx_destroy_image(info->mlx, info->img);
	if (issue == 'c')
		write(1, "Error: Information couldn't be retrieved, try again\n", 52);
	if (errors == 12 || errors == 123)
		mlx_destroy_window(info->mlx, info->win);
	if (issue == 'b')
		write(1, "Error: Image couldn't be created, try again\n", 44);
	if (errors == 1 || errors == 12 || errors == 123)
	{
		mlx_destroy_display(info->mlx);
		free (info->mlx);
	}
	if (issue == 'a')
		write(1, "Error: Window not created, try again\n", 37);
	if (issue == 'a' || issue == 'b' || issue == 'c' || issue == 'z')
		exit(1);
	else
		exit(0);
}
