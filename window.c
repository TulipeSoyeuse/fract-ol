/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:11 by romain            #+#    #+#             */
/*   Updated: 2023/12/14 14:18:59 by romain           ###   ########.fr       */
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

t_window	init(void)
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
	image.x_min = -3;
	image.x_max = 3;
	image.y_min = -3;
	image.y_max = 3;
	win.current_img = NULL;
	render_img(&image, &win);
	return (win);
}
