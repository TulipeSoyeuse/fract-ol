/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:55 by romain            #+#    #+#             */
/*   Updated: 2024/02/08 11:22:58 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error(int error)
{
	if (error == 1)
		write(2,"something went wrong with the image creation !",46);
	exit(EXIT_FAILURE);
}
