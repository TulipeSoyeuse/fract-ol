/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:20:23 by romain            #+#    #+#             */
/*   Updated: 2024/02/21 14:11:18 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pallette	get_base_pal(void)
{
	t_pallette	p;

	p.c9 = 0x03071E;
	p.c8 = 0x211C1B;
	p.c7 = 0x3D3019;
	p.c6 = 0x594417;
	p.c5 = 0x745814;
	p.c4 = 0xAC7F0F;
	p.c3 = 0xC8930D;
	p.c2 = 0xE3A60A;
	p.c1 = 0xFFBA08;
	return (p);
}

t_pallette	get_color_pallette(char *s)
{
	if (ft_strncmp(s, "base", ft_strlen(s)) == 0)
		return (get_base_pal());
	else
		return (get_base_pal());
}
