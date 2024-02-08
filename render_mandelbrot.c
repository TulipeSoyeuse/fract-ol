/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:20:26 by romain            #+#    #+#             */
/*   Updated: 2024/02/08 11:29:04 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	modulus(double r, double i)
{
	double	res;

	res = r*r + i*i;
	return (res);
}

void	render_img_mendelbrot(t_img *i, t_window *w)
{
	size_t	x;
	size_t	y;
	double	step_x;
	double	step_y;

	y = 0;
	step_x = (double)(i->x_max - i->x_min) / LENGTH;
	step_y = (double)(i->y_max - i->y_min) / WIDTH;
	while (y < WIDTH)
	{
		x = -1;
		while (++x < LENGTH)
			compute_image(i, x, y, resolve(i->x_min + x * step_x, i->y_max - y
					* step_y, 0, 0));
		y++;
	}
	mlx_put_image_to_window(w->mlx, w->mlx_win, i->img, 0, 0);
	if (w->current_img.img)
	{
		mlx_destroy_image(w->mlx, w->current_img.img);
		w->current_img.img = NULL;
	}
	w->current_img = *i;
}
