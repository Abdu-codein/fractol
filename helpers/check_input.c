/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:16:15 by amardini          #+#    #+#             */
/*   Updated: 2026/06/08 15:50:36 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	ft_strncmp(const char *sen1, const char *sen2, size_t n)
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

static int	ft_is_double(char *s)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9' )
			i++;
		else if (s[i] == '.')
		{
			dot_count++;
			i++;
		}
		else if (dot_count > 1 || !(s[i] >= '0' && s[i] <= '9' ))
			return (0);
	}
	return (1);
}

void	user_input(int argc, char **argv, t_fractal *f)
{
	if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)
			|| !ft_strncmp(argv[1], "Mandelbrot", 10)))
	{
		mandelbrot_design(argv, f);
	}
	else if ((argc == 4 && (!ft_strncmp(argv[1], "julia", 5)
				|| !ft_strncmp(argv[1], "Julia", 5))))
	{
		if (ft_is_double(argv[2]) == 0 || ft_is_double(argv[3]) == 0)
			m_error();
		julia_design(argv, f);
	}
	else if (argc == 2 && (!ft_strncmp(argv[1], "burning_ship", 12) ||
							!ft_strncmp(argv[1], "Burning_ship", 12) ||
							!ft_strncmp(argv[1], "burning ship", 12) ||
							!ft_strncmp(argv[1], "Burning ship", 12)))
	{
		burning_design(argv, f);
	}
	else
		m_error();
	return ;
}
