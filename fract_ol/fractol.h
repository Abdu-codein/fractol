/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:46:17 by amardini          #+#    #+#             */
/*   Updated: 2026/06/02 23:27:28 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fractal
{
    
}   t_fractal;

int	    ft_strncmp(const char *sen1, const char *sen2, size_t n);
void	m_error(void);
void	user_input(int argc, char **argv, t_fractal *f);