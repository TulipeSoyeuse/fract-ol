/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:31:30 by romain            #+#    #+#             */
/*   Updated: 2024/02/08 11:41:56 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void arg3(char *arg1, char *arg2)
{
	t_window	mlx;

	if (ft_strncmp(arg1, "Julia", 6) == 0)
	{
		mlx = init_julia(get_color_pallette(arg2));
		loop(mlx,0);
	}
	else if (ft_strncmp(arg1, "Mandelbrot", 6) == 0)
	{
		mlx = init_mendelbrot(get_color_pallette(arg2));
		loop(mlx,1);
	}
}

void arg2(char *arg)
{
	t_window	mlx;

	if (ft_strncmp(arg, "Julia", 6) == 0)
	{
		mlx = init_julia(get_color_pallette("dark"));
		loop(mlx,0);
	}
	else if (ft_strncmp(arg, "Mandelbrot", 6) == 0)
	{
		mlx = init_mendelbrot(get_color_pallette("dark"));
		loop(mlx,1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		arg2(av[1]);
	if (ac == 3)
		arg3(av[1], av[2]);
}
