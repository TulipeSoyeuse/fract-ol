/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:31:34 by romain            #+#    #+#             */
/*   Updated: 2024/02/21 14:55:25 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_P 112
# define KEY_M 109
# define KEY_I 105
# define KEY_V 118

# define MOVE_FACTOR 20
# define LENGTH 1080
# define WIDTH 1080
# define ITER_NB 70
# define ZOOM_FACTOR 0.8

typedef struct s_pallete
{
	int			c1;
	int			c2;
	int			c3;
	int			c4;
	int			c5;
	int			c6;
	int			c7;
	int			c8;
	int			c9;
}				t_pallette;

typedef struct s_img
{
	void		*img;
	char		*addr;

	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;

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
	double		c;
	size_t		iter;
}				t_window;

t_window		init_julia(t_pallette p, double c);
void			error(int error, t_window *mlx);
int				ft_exit(t_window *mlx);
void			render_img_julia(t_img *i, t_window *w);
t_pallette		get_color_pallette(char *s);
void			compute_image(t_img *img, int x, int y, int iter,
					int total_iter);
double			modulus(double r, double i);
t_window		init_mendelbrot(t_pallette p);
void			render_img_mendelbrot(t_img *i, t_window *w);
void			loop(t_window mlx, int v);
int				resolve(double a, double b, double znr, double zni,
					size_t iter);
t_img			get_new_image(t_window window);

t_img			up_iter(t_window *w);

t_img			zoom(t_window *mlx, double x, double y, double zoom);
t_img			mp_zoom(t_window *mlx, double zoom);
t_img			go_up(t_window *mlx);
t_img			go_down(t_window *mlx);
t_img			go_left(t_window *mlx);
t_img			go_right(t_window *mlx);
#endif
