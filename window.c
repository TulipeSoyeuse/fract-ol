/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:11 by romain            #+#    #+#             */
/*   Updated: 2023/12/13 15:58:34 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	init_win(void)
{
	t_window	res;
	void		*mlx;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, LENGTH, WIDTH, "Fract-ol");
	res.img = mlx_new_image(mlx, LENGTH, WIDTH);
	res.addr = mlx_get_window_addr(res.img, &res.bits_per_pixel,
			&res.line_length, &res.endian);
	if (!res.addr)
		error(1);
	res.x_min = -1;
	res.x_max = 1;
	res.y_min = -1;
	res.y_max = 1;
	return (res);
}
