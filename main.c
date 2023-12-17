/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:31:30 by romain            #+#    #+#             */
/*   Updated: 2023/12/17 14:32:59 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void arg3(char *arg1, char *arg2)
{
	t_window	mlx;

	if (ft_strncmp(arg1, "Julia", 6) == 0)
	{
		mlx = init_julia(get_color_pallette(arg2));
		mlx_loop(mlx.mlx);
	}
	else if (ft_strncmp(arg1, "Mandelbrot", 6) == 0)
	{
		mlx = init_mendelbrot(get_color_pallette(arg2));
		mlx_loop(mlx.mlx);
	}
}

void arg2(char *arg)
{
	t_window	mlx;

	if (ft_strncmp(arg, "Julia", 6) == 0)
	{
		mlx = init_julia(get_color_pallette("dark"));
		mlx_loop(mlx.mlx);
	}
	else if (ft_strncmp(arg, "Mandelbrot", 6) == 0)
	{
		mlx = init_mendelbrot(get_color_pallette("dark"));
		mlx_loop(mlx.mlx);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		arg2(av[1]);
	if (ac == 3)
		arg3(av[1], av[2]);
}
