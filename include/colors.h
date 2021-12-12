/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:40:26 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/12 12:32:46 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

enum e_colors{
	BLACK = 0x00000000,
	WHITE = 0x00FFFFFF,
	RED = 0x00C80000,
	PINK = 0x00FF91FF,
	LIME = 0x0000C800,
	BLUE = 0x000000FF,
	YELLOW = 0x00FFF000,
	CYAN = 0x0000FFFF,
	FUCHSIA = 0x00FF00FF,
	SILVER = 0x00C0C0C0,
	GREY = 0x00333333,
	GREEN = 0x00008000,
	PURPLE = 0x00800080,
	TEAL = 0x0008080
};

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	float	r_step;
	float	g_step;
	float	b_step;
	int		value;
}		t_color;

t_color	color(int value);
int		add_color_step(int bgn, t_color step);

#endif