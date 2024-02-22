/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:55 by romain            #+#    #+#             */
/*   Updated: 2024/02/22 12:29:32 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(int error, t_window *mlx)
{
	if (error == 1)
		write(2, "something went wrong with the image creation !", 46);
	if (error == 2)
		perror("fractol:");
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

int	ft_exit(t_window *mlx)
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
	return (0);
}
