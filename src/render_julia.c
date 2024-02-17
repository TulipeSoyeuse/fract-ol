/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:32:01 by romain            #+#    #+#             */
/*   Updated: 2024/02/17 23:17:05 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_image(t_img *img, int x, int y, int iter)
{
	char	*dst;
	int		color;
	double	val;

	val = (double)iter / (double)ITER_NB;
	if (val > 0.8)
		color = 0;
	else if (val < 0.2)
		color = img->p.c1;
	else if (val < 0.4)
		color = img->p.c2;
	else if (val < 0.6)
		color = img->p.c3;
	else
		color = img->p.c4;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	resolve(double a, double b, double znr, double zni)
{
	size_t	i;
	double	tmp;

	i = 0;
	while (i++ < ITER_NB)
	{
		if (modulus(znr, zni) > 4.0)
			break ;
		tmp = znr;
		znr = znr * znr - zni * zni + a;
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

	y = 0;
	step_x = (i->x_max - i->x_min) / LENGTH;
	step_y = (i->y_max - i->y_min) / WIDTH;
	while (y < WIDTH)
	{
		x = -1;
		while (++x < LENGTH)
			compute_image(i, x, y, resolve(w->c, 0.01, i->x_min + x * step_x,
					i->y_max - y * step_y));
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
