/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:17:32 by romain            #+#    #+#             */
/*   Updated: 2024/02/18 11:30:43 by rdupeux          ###   ########.fr       */
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
