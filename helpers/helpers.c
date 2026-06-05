/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:56:41 by amardini          #+#    #+#             */
/*   Updated: 2026/06/05 18:21:56 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

double atod(char *number)
{
	int i;
	int sign;
	double result;
	double after;

	sign = 1;
	i = 0;
	after = 1;
	
	if (number[i] == '-')
		sign = sign * -1;
	if (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i] >= '0' && number[i] <= '9')
		result = result * 10 + (number[i++] - '0');
		if (number[i] == '.')
			i++;
	while (number[i] >= '0' && number[i] <= '9')
	{
		after = after / 10;
		result = result + (number[i++] - '0') * after;
	}
	return (sign * result);
}
