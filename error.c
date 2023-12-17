/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:55 by romain            #+#    #+#             */
/*   Updated: 2023/12/13 16:50:33 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error(int error)
{
	if (error == 1)
		write(2,"something went wrong with the image creation !",46);
		exit(EXIT_FAILURE);
}
