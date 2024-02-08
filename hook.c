/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:09:04 by romain            #+#    #+#             */
/*   Updated: 2024/02/08 12:04:22 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	zoom(t_window *mlx, double x, double y, double zoom)
{
	t_img	ni;
	double	translate_x;
	double	translate_y;

	ni = get_new_image(*mlx);
	translate_x = (mlx->current_img.x_min + x * (mlx->current_img.x_max
				- mlx->current_img.x_min) / LENGTH) - (mlx->current_img.x_max
			- (mlx->current_img.x_max - mlx->current_img.x_min) / 2);
	translate_y = (mlx->current_img.y_max - y * (mlx->current_img.y_max
				- mlx->current_img.y_min) / WIDTH) - (mlx->current_img.y_max
			- (mlx->current_img.y_max - mlx->current_img.y_min) / 2);
	ni.x_min = (mlx->current_img.x_min + translate_x) * zoom;
	ni.x_max = (mlx->current_img.x_max + translate_x) * zoom;
	ni.y_min = (mlx->current_img.y_min + translate_y) * zoom;
	ni.y_max = (mlx->current_img.y_max + translate_y) * zoom;
	ni.p = mlx->current_img.p;
	return (ni);
}

int	mouse_hook_julia(int button, int x, int y, t_window *mlx)
{
	t_img	img;

	if (button == 4)
		img = zoom(mlx, x, y, ZOOM_FACTOR);
	else if (button == 5)
		img = zoom(mlx, x, y, 2 - ZOOM_FACTOR);
	else
		return (0);
	render_img_julia(&img, mlx);
	return (0);
}

int	mouse_hook_mendelbrot(int button, int x, int y, t_window *mlx)
{
	t_img	img;

	if (button == 4)
		img = zoom(mlx, x, y, ZOOM_FACTOR);
	if (button == 5)
		img = zoom(mlx, x, y, 2 - ZOOM_FACTOR);
	else
		return (0);
	render_img_mendelbrot(&img, mlx);
	return (button);
}

int	key_hook(int button, t_window *mlx)
{
	if (button == 65307)
	{
		mlx_destroy_image(mlx->mlx, mlx->current_img.img);
		mlx_destroy_window(mlx->mlx,mlx->mlx_win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit(0);
	}
	return (0);
}

void	loop(t_window mlx, int v)
{
	if (v)
	{
		mlx_mouse_hook(mlx.mlx_win, &mouse_hook_mendelbrot, &mlx);
		mlx_key_hook(mlx.mlx_win, &key_hook, &mlx);	
	}
	else
	{
		mlx_key_hook(mlx.mlx_win, &key_hook, &mlx);
		mlx_mouse_hook(mlx.mlx_win, &mouse_hook_julia, &mlx);
	}
	mlx_loop(mlx.mlx);
}
