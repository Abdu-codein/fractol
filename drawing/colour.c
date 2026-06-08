/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 05:54:32 by amardini          #+#    #+#             */
/*   Updated: 2026/06/06 05:54:32 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	dynamic_colour(int iter, t_fractal *info)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == info->max_iteration)
		return (0x000000);
	t = (double)iter / (double)info->max_iteration;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	single_colour(int iter, int color_mode, t_fractal *info)
{
	double	t;
	int		brightness;

	if (iter == info->max_iteration)
		return (0x000000);
	t = (double)iter / (double)info->max_iteration;
	brightness = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	if (color_mode == 2)
		return (brightness << 16);
	else if (color_mode == 3)
		return (brightness << 8);
	else if (color_mode == 4)
		return (brightness);
	return (0x000000);
}
