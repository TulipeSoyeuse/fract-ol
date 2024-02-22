/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:20:26 by romain            #+#    #+#             */
/*   Updated: 2024/02/22 13:05:46 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	modulus(double r, double i)
{
	double	res;

	res = r * r + i * i;
	return (res);
}

void	threading_compute(t_thread_arg *arg)
{
	size_t	x;
	size_t	i;

	i = arg->y;
	while (arg->y < WIDTH && arg->y < i + 40)
	{
		x = -1;
		while (++x < LENGTH)
			compute_image(i, x, arg->y, resolve(arg->i->x_min + x * arg->step_x,
					arg->i->y_max - arg->y * arg->step_y, 0, 0, arg->w->iter),
				arg->w->iter);
		arg->y++;
	}
}

void	render_img_mendelbrot(t_img *i, t_window *w)
{
	size_t			x;
	size_t			y;
	double			step_x;
	double			step_y;
	t_thread_arg	arg;

	y = 0;
	step_x = (double)(i->x_max - i->x_min) / LENGTH;
	step_y = (double)(i->y_max - i->y_min) / WIDTH;
	while (y < WIDTH)
	{
		pthread_create()
	}
	mlx_put_image_to_window(w->mlx, w->mlx_win, i->img, 0, 0);
	if (w->current_img.img)
	{
		mlx_destroy_image(w->mlx, w->current_img.img);
		w->current_img.img = NULL;
	}
	w->current_img = *i;
}
