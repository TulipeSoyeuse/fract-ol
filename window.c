/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:11 by romain            #+#    #+#             */
/*   Updated: 2023/12/17 14:28:16 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img get_image(t_window window)
{
	t_img image;

	image.img = mlx_new_image(window.mlx, LENGTH, WIDTH);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	if (!image.addr)
		error(1);
	return (image);
}

t_img get_image_copy(t_img origin, t_window window)
{
	t_img img;

	img = get_image(window);

	img.x_max = origin.x_max;
	img.x_min = origin.x_min;
	img.y_max = origin.y_max;
	img.x_min = origin.x_min;
	return (img);
}

t_window	init_julia(t_pallette p)
{
	t_window	win;
	t_img		image;

	win.mlx = mlx_init();
		if (!win.mlx)
			error(1);
	win.mlx_win = mlx_new_window(win.mlx, LENGTH, WIDTH, "Fract-ol");
		if (!win.mlx_win)
			error(1);
	image = get_image(win);
	image.x_min = -2;
	image.x_max = 2;
	image.y_min = -2;
	image.y_max = 2;
	win.current_img = NULL;
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
			error(1);
	win.mlx_win = mlx_new_window(win.mlx, LENGTH, WIDTH, "Fract-ol");
		if (!win.mlx_win)
			error(1);
	image = get_image(win);
	image.x_min = -2;
	image.x_max = 2;
	image.y_min = -2;
	image.y_max = 2;
	win.current_img = NULL;
	image.p = p;
	render_img_mendelbrot(&image, &win);
	return (win);
}
