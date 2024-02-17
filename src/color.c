/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:20:23 by romain            #+#    #+#             */
/*   Updated: 2023/12/17 14:16:01 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pallette	get_dark_pal(void)
{
	t_pallette	p;

	p.c4 = 0x392467;
	p.c3 = 0x5D3587;
	p.c2 = 0xA367B1;
	p.c1 = 0xFFD1E3;
	return (p);
}

t_pallette	get_purple_pal(void)
{
	t_pallette	p;

	p.c4 = 0x191919;
	p.c3 = 0x750E21;
	p.c2 = 0xE3651D;
	p.c1 = 0xBED754;
	return (p);
}

t_pallette	get_sage_pal(void)
{
	t_pallette	p;

	p.c4 = 0x092635;
	p.c3 = 0x1B4242;
	p.c2 = 0x5C8374;
	p.c1 = 0x9EC8B9;
	return (p);
}

t_pallette	get_maroon_pal(void)
{
	t_pallette	p;

	p.c4 = 0x5F0F40;
	p.c3 = 0xFB8B24;
	p.c2 = 0xE36414;
	p.c1 = 0x9A031E;
	return (p);
}

t_pallette	get_color_pallette(char *s)
{
	if (ft_strncmp(s, "purple", 7) == 0)
		return (get_purple_pal());
	if (ft_strncmp(s, "dark", 5) == 0)
		return (get_dark_pal());
	if (ft_strncmp(s, "sage", 5) == 0)
		return (get_sage_pal());
	else
		return (get_maroon_pal());
}
