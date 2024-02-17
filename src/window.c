/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:11 by romain            #+#    #+#             */
/*   Updated: 2024/02/08 12:18:38 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	get_new_image(t_window window)
{
	t_img	image;

	image.img = mlx_new_image(window.mlx, LENGTH, WIDTH);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	if (!image.addr)
		error(1, &window);
	return (image);
}

t_window	init_julia(t_pallette p)
{
	t_window	win;
	t_img		image;

	win.current_img.img = NULL;
	win.mlx = NULL;
	win.mlx_win = NULL;
	win.mlx = mlx_init();
	if (!win.mlx)
		error(1, &win);
	win.mlx_win = mlx_new_window(win.mlx, LENGTH, WIDTH, "Fract-ol");
	if (!win.mlx_win)
		error(1, &win);
	image = get_new_image(win);
	image.x_min = -2.0;
	image.x_max = 2.0;
	image.y_min = -2.0;
	image.y_max = 2.0;
	win.current_img.img = NULL;
	image.p = p;
	render_img_julia(&image, &win);
	return (win);
}

t_window	init_mendelbrot(t_pallette p)
{
	t_window	win;
	t_img		image;

	win.mlx = mlx_init();
	if (!win.mlx)
		error(1, &win);
	win.mlx_win = mlx_new_window(win.mlx, LENGTH, WIDTH, "Fract-ol");
	if (!win.mlx_win)
		error(1, &win);
	image = get_new_image(win);
	image.x_min = -2.0;
	image.x_max = 2.0;
	image.y_min = -2.0;
	image.y_max = 2.0;
	win.current_img.img = NULL;
	image.p = p;
	render_img_mendelbrot(&image, &win);
	return (win);
}
