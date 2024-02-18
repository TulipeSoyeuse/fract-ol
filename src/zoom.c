/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:48:18 by romain            #+#    #+#             */
/*   Updated: 2024/02/18 11:25:42 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	zoom(t_window *mlx, double x, double y, double zoom)
{
	t_img		ni;
	long double	translate_x;
	long double	translate_y;

	translate_x = (mlx->current_img.x_min + x * (mlx->current_img.x_max
				- mlx->current_img.x_min) / LENGTH) - (mlx->current_img.x_max
			- (mlx->current_img.x_max - mlx->current_img.x_min) / 2);
	translate_y = (mlx->current_img.y_max - y * (mlx->current_img.y_max
				- mlx->current_img.y_min) / WIDTH) - (mlx->current_img.y_max
			- (mlx->current_img.y_max - mlx->current_img.y_min) / 2);
	ni = get_new_image(*mlx);
	ni.x_min = (mlx->current_img.x_min + translate_x) * zoom;
	ni.x_max = (mlx->current_img.x_max + translate_x) * zoom;
	ni.y_min = (mlx->current_img.y_min + translate_y) * zoom;
	ni.y_max = (mlx->current_img.y_max + translate_y) * zoom;
	ni.p = mlx->current_img.p;
	return (ni);
}

t_img	mp_zoom(t_window *mlx, double zoom)
{
	t_img	ni;
	double	center_x;
	double	center_y;

	center_x = mlx->current_img.x_max - mlx->current_img.x_min;
	center_y = mlx->current_img.y_min - mlx->current_img.y_max;
	ni = get_new_image(*mlx);
	ni.x_min = mlx->current_img.x_min + (center_x - zoom * center_x) / 2;
	ni.x_max = mlx->current_img.x_min + zoom * center_x;
	ni.y_max = mlx->current_img.y_max + (center_y - zoom * center_y) / 2;
	ni.y_min = mlx->current_img.y_max + zoom * center_y;
	ni.p = mlx->current_img.p;
	return (ni);
}
