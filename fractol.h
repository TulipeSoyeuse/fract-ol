/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:31:34 by romain            #+#    #+#             */
/*   Updated: 2023/12/17 14:02:43 by romain           ###   ########.fr       */
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

# define LENGTH 1920
# define WIDTH 1080
# define ITER_NB 75

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

	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;

	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_pallette	p;
}				t_img;

typedef struct s_window
{
	void		*mlx;
	void		*mlx_win;
	t_img		*current_img;
}				t_window;

t_window		init_julia(t_pallette p);
void			error(int error);
void			render_img_julia(t_img *i, t_window *w);
t_img			get_image_copy(t_img origin, t_window window);
t_pallette		get_color_pallette(char *s);
#endif
