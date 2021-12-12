/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguilar <faguilar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:22:01 by faguilar          #+#    #+#             */
/*   Updated: 2021/12/12 12:24:29 by faguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void ft_print_data(t_wireframe *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_grid[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}

void axis(t_wireframe *data)
{
	t_wireframe	*axis;

	axis = (t_wireframe *)malloc(sizeof(t_wireframe));
	read_wireframe(axis, "test_maps/axis.fdf");
	axis->mlx_ptr = data->mlx_ptr;
	axis->win_ptr = data->win_ptr;
	axis->zoom = 20;
	axis->angle = data->angle;
	axis->z_scale = 10;
	axis->position = point(950, 950, 0, 0);
	draw(axis);
	free(axis);
}

int	deal_key(int key, t_wireframe *data)
{
	if (key == KEY_LEFT)
		data->position.x -= 10;
	else if (key == KEY_UP)
		data->position.y -= 10;
	else if (key == KEY_RIGHT)
		data->position.x += 10;
	else if (key == KEY_DOWN)
		data->position.y += 10;
	else if (key == KEY_W)
		data->zoom += 1;
	else if (key == KEY_S)
		data->zoom -= 1;
	else if (key == KEY_A)
		data->rotation_z = angle(data->rotation_z.deg + 5);
	else if (key == KEY_D)
		data->rotation_z = angle(data->rotation_z.deg - 5);
	else if (key == KEY_Z)
		data->rotation_y = angle(data->rotation_y.deg + 5);
	else if (key == KEY_X)
		data->rotation_y = angle(data->rotation_y.deg - 5);
	else if (key == KEY_ESC)
		shutdown(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	axis(data);
	return (0);
}

void	init_window(t_wireframe *data, char *file_name)
{
	char	*title;
	
	title = ft_strjoin("FDF - ", file_name);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, SCR_WIDTH, SCR_HEIGHT, title);
	data->angle = angle(60);
	data->zoom = (SCR_HEIGHT * 0.9) / ((data->width + data->height) * data->angle.cos);
	data->rotation_x = angle(0);
	data->rotation_y = angle(0);
	data->rotation_z = angle(0);
	data->center = point(SCR_WIDTH / 2, SCR_HEIGHT / 2, 0, 0);
	data->z_scale = 2;
	data->position = point(SCR_WIDTH / 2, SCR_HEIGHT / 2, 0, 0);
}

int	main(int argc, char **argv)
{
	t_wireframe	*data;

	if (argc != 2)
		return (0);
	data = (t_wireframe *)malloc(sizeof(t_wireframe));
	read_wireframe(data, argv[1]);
	// ft_print_data(data); // debug
	init_window(data, argv[1]);
	axis(data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	// sleep(5);
	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop(data->mlx_ptr);
	return (0);
}
