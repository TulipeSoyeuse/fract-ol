/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:32:01 by romain            #+#    #+#             */
/*   Updated: 2023/12/17 14:22:07 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_image(t_img *img, int x, int y, int iter)
{
	char	*dst;
	int		color;
	int		split;

	split = ITER_NB / 4;
	if (iter < split)
		color = img->p.c1;
	else if (iter < 2 * split)
		color = img->p.c2;
	else if (iter < 3 * split)
		color = img->p.c3;
	else
		color = img->p.c4;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	modulus(double r, double i)
{
	double	res;

	res = pow(r, 2) + pow(i, 2);
	return (res);
}

int	resolve_julia(double a, double b, double znr, double zni)
{
	size_t	i;
	double	tmp;

	i = 0;
	while (i++ < ITER_NB)
	{
		if (modulus(znr, zni) > 4.0)
			break ;
		tmp = znr;
		znr = pow(znr, 2) - pow(zni, 2) + a;
		zni = 2 * tmp * zni + b;
	}
	return (i);
}

void	render_img_julia(t_img *i, t_window *w)
{
	size_t	x;
	size_t	y;
	double	step_x;
	double	step_y;

	y = WIDTH;
	step_x = (double)(i->x_max - i->x_min) / LENGTH;
	step_y = (double)(i->y_max - i->y_min) / WIDTH;
	while (y > 0)
	{
		x = -1;
		while (++x < LENGTH)
			compute_image(i, x, y, resolve_julia(0.285, 0.01, i->x_min + x
					* step_x, i->y_min + y * step_y));
		y--;
	}
	mlx_put_image_to_window(w->mlx, w->mlx_win, i->img, 0, 0);
	if (w->current_img)
	{
		mlx_destroy_image(w->mlx, w->current_img->img);
		w->current_img = NULL;
	}
	w->current_img = i;
}
