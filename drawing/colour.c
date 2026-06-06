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

int	dynamic_colour(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	// If it reached the max, it's inside the set (Black)
	if (iter == max_iter) 
		return (0x000000);

	// Get a percentage of how long it survived (0.0 to 1.0)
	t = (double)iter / (double)max_iter;

	// Use sine functions to generate smooth, unique patterns for R, G, and B
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	// Bit-shift them together into a single TRGB integer
	return ((r << 16) | (g << 8) | b);
}

int single_colour(int iter, int max_iter, int color_mode)
{
    double t;
    int    brightness;

    if (iter == max_iter)
        return (0x000000); // Inside the set is always black

    t = (double)iter / (double)max_iter;
    
    // This balanced math peaks beautifully right at t = 0.5
    brightness = (int)(15 * (1 - t) * (1 - t) * t * t * 255);

    if (color_mode == 2)      // Pure Smooth Red Mode
        return (brightness << 16);
    else if (color_mode == 3) // Pure Smooth Green Mode
        return (brightness << 8);
    else if (color_mode == 4) // Pure Smooth Blue Mode
        return (brightness);
        
    return (0x000000);
}

//FIX THIS PAGE