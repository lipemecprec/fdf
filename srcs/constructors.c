/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:01:40 by faguilar          #+#    #+#             */
/*   Updated: 2021/11/24 22:03:13 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_coord	new_coord(int x, int y, int z)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}

t_coord new_proj(int x, int y, int z, t_angle a)
{
	t_coord p;

	p.x = x;
	p.y = y * a.tan + z;
	p.z = 0;
	return (p);
}

t_pair	new_pair(t_coord bgn, t_coord end, int color)
{
	t_pair	pair;

	pair.bgn = bgn;
	pair.end = end;
	pair.color = color;
	return (pair);
}

t_pair	new_line(float x, float y, float x1, float y1)
{
	t_pair	pair;

	pair.bgn = new_coord(x, y, 0);
	pair.end = new_coord(x1, y1, 0);
	pair.color = 0xffffff;
	return (pair);
}

t_angle	new_angle(double deg)
{
	t_angle	angle;

	angle.deg = deg;
	angle.rad = PI / 180 * deg;
	angle.sin = sin(angle.rad);
	angle.cos = cos(angle.rad);
	angle.tan = tan(angle.rad);
	return (angle);
}
