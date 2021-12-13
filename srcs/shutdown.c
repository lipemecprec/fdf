/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:27:22 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/12 10:06:13 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	free_wireframe_data(t_wireframe *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
		free(data->z_grid[i++]);
	free(data->z_grid);
	free(data->mlx_ptr);
	free(data->win_ptr);
	free(data);
}

void	shutdown(t_wireframe *data)
{
	mlx_destroy_image(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_wireframe_data(data);
}
