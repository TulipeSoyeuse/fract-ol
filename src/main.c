/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:31:30 by romain            #+#    #+#             */
/*   Updated: 2024/02/18 12:12:12 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	launch_julia(int ac, char **av)
{
	t_window	mlx;

	if (ac == 3)
		mlx = init_julia(get_color_pallette(av[2]), 0.285);
	if (ac == 4)
		mlx = init_julia(get_color_pallette(av[2]), ft_atof(av[3]));
	if (ac > 4)
		display_man();
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
		display_man();
}
