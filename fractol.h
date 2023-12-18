/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:31:34 by romain            #+#    #+#             */
/*   Updated: 2023/12/18 11:23:48 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define LENGTH 1080
# define WIDTH 1080
# define ITER_NB 200
# define ZOOM_FACTOR 0.8

typedef struct s_pallete
{
	int			c1;
	int			c2;
	int			c3;
	int			c4;
}				t_pallette;

typedef struct s_img
{
	void		*img;
	char		*addr;

	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;

	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_pallette	p;
}				t_img;

typedef struct s_window
{
	void		*mlx;
	void		*mlx_win;
	t_img		current_img;
}				t_window;

t_window		init_julia(t_pallette p);
void			error(int error);
void			render_img_julia(t_img *i, t_window *w);
t_pallette		get_color_pallette(char *s);
void			compute_image(t_img *img, int x, int y, int iter);
double			modulus(double r, double i);
t_window		init_mendelbrot(t_pallette p);
void			render_img_mendelbrot(t_img *i, t_window *w);
void			loop(t_window mlx, int v);
int				resolve(double a, double b, double znr, double zni);
t_img			get_new_image(t_window window);
#endif
