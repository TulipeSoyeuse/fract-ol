/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:31:34 by romain            #+#    #+#             */
/*   Updated: 2023/12/13 15:55:23 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include "mlx/mlx.h"
# include <math.h>
# define LENGTH 1920
# define WIDTH 1080

typedef struct s_window
{
	void	*mlx;
	void	*img;
	char	*addr;

	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_window;

t_window	init_win(void);
void		error(int error);
#endif
