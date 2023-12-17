/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:31:34 by romain            #+#    #+#             */
/*   Updated: 2023/12/14 13:49:12 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define LENGTH 1920
# define WIDTH 1080
# define ITER_NB 75

typedef struct s_img
{
	void	*img;
	char	*addr;

	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	t_img	*current_img;
}			t_window;

t_window	init(void);
void		error(int error);
void		render_img(t_img *i, t_window *w);
#endif
