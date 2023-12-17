/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:32:01 by romain            #+#    #+#             */
/*   Updated: 2023/12/14 15:07:35 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	level(int i)
{
	if (i < ITER_NB/2)
		return (0x00FF0000);
	else
		return (0x0000FF00);
}

double	modulus(double R, double I)
{
	double	res;

	res = pow(R, 2) + pow(I, 2);
	return (sqrt(res));
}

int	resolve_Julia(double a, double b, double ZnR, double ZnI)
{
	size_t	i;
	double	tmp;

	i = 0;
	while (i++ < ITER_NB)
	{
		if (modulus(ZnR, ZnI) > 2.0)
			break ;
		tmp = ZnR;
		ZnR = pow(ZnR, 2) - pow(ZnI, 2) + a;
		ZnI = 2 * tmp * ZnI + b;
	}
	return (level(i));
}

void	render_img(t_img *i, t_window *w)
{
	size_t	x;
	size_t	y;
	double	step_x;
	double	step_y;

	y = 0;
	step_x = (double) (i->x_max - i->x_min) / LENGTH;
	step_y = (double) (i->y_max - i->y_min) / WIDTH;
	while (y < WIDTH)
	{
		x = -1;
		while (++x < LENGTH)
			my_mlx_pixel_put(i, x, y, resolve_Julia(0.285, 0.01,
					x * step_x, y * step_y));
		y++;
	}
	mlx_put_image_to_window(w->mlx, w->mlx_win, i->img, 0, 0);
	if (w->current_img)
	{
		mlx_destroy_image(w->mlx, w->current_img->img);
		w->current_img = NULL;
	}
	w->current_img = i;
}
