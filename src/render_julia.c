/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:32:01 by romain            #+#    #+#             */
/*   Updated: 2024/02/21 14:55:55 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_image(t_img *img, int x, int y, int iter, int total_iter)
{
	char	*dst;
	int		color;
	double	val;

	val = (double)iter / (double)total_iter;
	if (val < 0.1)
		color = img->p.c1;
	else if (val < 0.2)
		color = img->p.c2;
	else if (val < 0.3)
		color = img->p.c3;
	else if (val < 0.4)
		color = img->p.c4;
	else if (val < 0.5)
		color = img->p.c5;
	else if (val < 0.6)
		color = img->p.c6;
	else if (val < 0.7)
		color = img->p.c7;
	else if (val < 0.8)
		color = img->p.c8;
	else if (val < 0.9)
		color = img->p.c9;
	else
		color = 0x0;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	resolve(double a, double b, double znr, double zni, size_t iter)
{
	size_t	i;
	double	tmp;

	(void)iter;
	i = 0;
	while (i++ < iter)
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
					i->y_max - y * step_y, w->iter), w->iter);
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
