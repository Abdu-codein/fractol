/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nlibft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:49:39 by amardini          #+#    #+#             */
/*   Updated: 2026/06/02 22:50:00 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int	ft_strncmp(const char *sen1, const char *sen2, size_t n)
{
	size_t	reader;

	reader = 0;
	while (reader < n && ((unsigned char)sen1[reader] != '\0'
			|| (unsigned char)sen2[reader] != '\0'))
	{
		if ((unsigned char)sen1[reader] != (unsigned char)sen2[reader])
		{
			return ((unsigned char)sen1[reader] - (unsigned char)sen2[reader]);
		}
		reader++;
	}
	return (0);
}