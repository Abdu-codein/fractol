/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amardini <amardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:46:17 by amardini          #+#    #+#             */
/*   Updated: 2026/06/08 17:55:10 by amardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include <math.h>

# define DIM_Z 800
# define DIM_Y 800
# define ZOOM_IN 1.2
# define ZOOM_OUT 0.8

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		colour;
	int		max_iteration;
	int		whatis;
	double	max_real;
	double	min_real;
	double	max_imaginary;
	double	min_imaginary;
	double	julia_real;
	double	julia_imaginary;
}	t_fractal;

void	m_error(void);
void	user_input(int argc, char **argv, t_fractal *f);
double	atod(char *number);
void	distruc_error(t_fractal *info, int errors, char issue);
void	mandelbrot_design(char **argv, t_fractal *data);
void	julia_design(char **argv, t_fractal *data);
int		julia_cal(double coor_x, double coor_y, t_fractal *info);
int		mandel_cal(double coor_x, double coor_y, t_fractal *info);
void	create_shape(t_fractal *info);
int		handle_mouse(int input, int x, int y, void *param);
int		handle_keys(int input, void *param);
int		dynamic_colour(int iter, t_fractal *info);
int		single_colour(int iter, int color_mode, t_fractal *info);
void	nu_error(void);
void	distruc_error(t_fractal *info, int errors, char issue);
void	window_create(t_fractal *info);
void	zoom_m(t_fractal *info, double zoom, int x, int y);
void	zoom_k(t_fractal *info, double zoom);
void	burning_design(char **argv, t_fractal *data);
int		ship_cal(double coor_x, double coor_y, t_fractal *info);

#endif