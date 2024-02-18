/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:52:16 by rdupeux           #+#    #+#             */
/*   Updated: 2024/02/18 11:57:00 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_man(void)
{
	write(STDOUT_FILENO, "Usage : ./fractol <Mandelbrot|Julia>", 37);
	write(STDOUT_FILENO, " <(optional)purple|dark|sage|(def)maroon>", 42);
	write(STDOUT_FILENO, " <(optional require color)", 27);
	write(STDOUT_FILENO, "init param for julia>\n", 23);
	exit(0);
}
