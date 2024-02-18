/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:09:04 by romain            #+#    #+#             */
/*   Updated: 2024/02/18 11:30:37 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	else if (button == 5)
	{
		img = zoom(mlx, x, y, 2 - ZOOM_FACTOR);
	}
	else
		return (0);
	render_img_mendelbrot(&img, mlx);
	return (button);
}

int	key_hook_julia(int button, t_window *mlx)
{
	t_img	img;

	if (button == KEY_ESC)
		ft_exit(mlx);
	else if (button == KEY_UP)
		img = go_up(mlx);
	else if (button == KEY_DOWN)
		img = go_down(mlx);
	else if (button == KEY_LEFT)
		img = go_left(mlx);
	else if (button == KEY_RIGHT)
		img = go_right(mlx);
	else if (button == KEY_P)
		img = mp_zoom(mlx, ZOOM_FACTOR);
	else if (button == KEY_M)
		img = mp_zoom(mlx, 2 - ZOOM_FACTOR);
	else
		return (0);
	render_img_julia(&img, mlx);
	return (0);
}

int	key_hook_mandelbrot(int button, t_window *mlx)
{
	t_img	img;

	if (button == KEY_ESC)
		ft_exit(mlx);
	else if (button == KEY_UP)
		img = go_up(mlx);
	else if (button == KEY_DOWN)
		img = go_down(mlx);
	else if (button == KEY_LEFT)
		img = go_left(mlx);
	else if (button == KEY_RIGHT)
		img = go_right(mlx);
	else if (button == KEY_P)
		img = mp_zoom(mlx, ZOOM_FACTOR);
	else if (button == KEY_M)
		img = mp_zoom(mlx, 1 + ZOOM_FACTOR);
	else
		return (0);
	render_img_mendelbrot(&img, mlx);
	return (0);
}

void	loop(t_window mlx, int v)
{
	if (v)
	{
		mlx_mouse_hook(mlx.mlx_win, &mouse_hook_mendelbrot, &mlx);
		mlx_key_hook(mlx.mlx_win, &key_hook_mandelbrot, &mlx);
	}
	else
	{
		mlx_mouse_hook(mlx.mlx_win, &mouse_hook_julia, &mlx);
		mlx_key_hook(mlx.mlx_win, &key_hook_julia, &mlx);
	}
	mlx_hook(mlx.mlx_win, EVENT_CLOSE_BTN, 0, ft_exit, &mlx);
	mlx_loop(mlx.mlx);
}
