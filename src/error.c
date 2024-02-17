/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:55 by romain            #+#    #+#             */
/*   Updated: 2024/02/08 12:18:35 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(int error, t_window *mlx)
{
	if (error == 1)
		write(2, "something went wrong with the image creation !", 46);
	if (mlx->current_img.img)
		mlx_destroy_image(mlx->mlx, mlx->current_img.img);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	exit(EXIT_FAILURE);
}

void	ft_exit(t_window *mlx)
{
	if (mlx->current_img.img)
		mlx_destroy_image(mlx->mlx, mlx->current_img.img);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	exit(EXIT_SUCCESS);
}
