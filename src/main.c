/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:31:30 by romain            #+#    #+#             */
/*   Updated: 2024/02/17 19:31:09 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	launch_julia(int ac, char **av)
{
	t_window	mlx;

	if (ac == 3)
	{
		if (ft_atof(av[2]) == 0)
			mlx = init_julia(get_color_pallette(av[2]), 0.285);
		else
			mlx = init_julia(get_color_pallette("dark"), ft_atof(av[2]));
	}
	if (ac == 4)
		mlx = init_julia(get_color_pallette(av[2]), ft_atof(av[3]));
	loop(mlx, 0);
}

void	arg3(int ac, char **av)
{
	t_window	mlx;

	if (ft_strncmp(av[1], "Julia", 6) == 0)
		launch_julia(ac, av);
	else if (ft_strncmp(av[1], "Mandelbrot", 6) == 0)
	{
		mlx = init_mendelbrot(get_color_pallette(av[2]));
		loop(mlx, 1);
	}
}

void	arg2(char *arg)
{
	t_window	mlx;

	if (ft_strncmp(arg, "Julia", 6) == 0)
	{
		mlx = init_julia(get_color_pallette("dark"), 0.285);
		loop(mlx, 0);
	}
	else if (ft_strncmp(arg, "Mandelbrot", 6) == 0)
	{
		mlx = init_mendelbrot(get_color_pallette("dark"));
		loop(mlx, 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		arg2(av[1]);
	if (ac > 2)
		arg3(ac, av);
	else
	{
		write(STDOUT_FILENO, "Usage : ./fractol <Mandelbrot|Julia>", 37);
		write(STDOUT_FILENO, " <(optional)purple|dark|sage|(def)maroon>", 42);
		write(STDOUT_FILENO, " <(optional) init param for julia>\n", 36);
	}
}
