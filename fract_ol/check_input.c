/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:16:15 by amardini          #+#    #+#             */
/*   Updated: 2026/06/02 23:30:34 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	user_input(int argc, char **argv, t_fractal *f)
{
	if (argc == 2 && (!ft_strncmp(argv[1] ,"mandelbrot", 10) || !ft_strncmp(argv[1], "Mandelbrot", 10)))
	{
		//DEFINE WHAT MANDELBROT NEEDS
	}
	else if ((argc == 4  && (!ft_strncmp(argv[1] ,"julia", 5) || !ft_strncmp(argv[1], "Julia", 5))))
	{
		//CHECK IF INPUT FLOAT MAKES SENSE
		//DEFINE WHAT JULIA NEEDS
	}
	else
		m_error();
}