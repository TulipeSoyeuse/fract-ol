/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:17:32 by romain            #+#    #+#             */
/*   Updated: 2024/02/21 15:09:43 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	go_right(t_window *mlx)
{
	t_img	ni;

	ni = get_new_image(*mlx);
	ni.x_min = mlx->current_img.x_min + (mlx->current_img.x_max
			- mlx->current_img.x_min) / MOVE_FACTOR;
	ni.x_max = mlx->current_img.x_max + (mlx->current_img.x_max
			- mlx->current_img.x_min) / MOVE_FACTOR;
	ni.y_max = mlx->current_img.y_max;
	ni.y_min = mlx->current_img.y_min;
	ni.p = mlx->current_img.p;
	return (ni);
}

t_img	go_left(t_window *mlx)
{
	t_img	ni;

	ni = get_new_image(*mlx);
	ni.x_min = mlx->current_img.x_min - (mlx->current_img.x_max
			- mlx->current_img.x_min) / MOVE_FACTOR;
	ni.x_max = mlx->current_img.x_max - (mlx->current_img.x_max
			- mlx->current_img.x_min) / MOVE_FACTOR;
	ni.y_max = mlx->current_img.y_max;
	ni.y_min = mlx->current_img.y_min;
	ni.p = mlx->current_img.p;
	return (ni);
}

t_img	go_down(t_window *mlx)
{
	t_img	ni;

	ni = get_new_image(*mlx);
	ni.y_min = mlx->current_img.y_min - (mlx->current_img.y_max
			- mlx->current_img.y_min) / MOVE_FACTOR;
	ni.y_max = mlx->current_img.y_max - (mlx->current_img.y_max
			- mlx->current_img.y_min) / MOVE_FACTOR;
	ni.x_max = mlx->current_img.x_max;
	ni.x_min = mlx->current_img.x_min;
	ni.p = mlx->current_img.p;
	return (ni);
}

t_img	go_up(t_window *mlx)
{
	t_img	ni;

	ni = get_new_image(*mlx);
	ni.y_min = mlx->current_img.y_min + (mlx->current_img.y_max
			- mlx->current_img.y_min) / MOVE_FACTOR;
	ni.y_max = mlx->current_img.y_max + (mlx->current_img.y_max
			- mlx->current_img.y_min) / MOVE_FACTOR;
	ni.x_max = mlx->current_img.x_max;
	ni.x_min = mlx->current_img.x_min;
	ni.p = mlx->current_img.p;
	return (ni);
}

t_img	up_iter(t_window *w)
{
	t_img	img;

	printf("ping\n");
	w->iter++;
	img = get_new_image(*w);
	img.p = w->current_img.p;
	img.x_max = w->current_img.x_max;
	img.x_min = w->current_img.x_min;
	img.y_max = w->current_img.y_max;
	img.y_min = w->current_img.y_min;
	return (img);
}
