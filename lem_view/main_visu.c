/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:13:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/22 02:25:50 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu.h"

int			ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static void	check_values(t_visu *visu)
{
	if (visu->x_max + visu->x_movement > 1920
				|| visu->x_max + visu->x_movement < 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	if (visu->y_max + visu->y_movement > 1080
				|| visu->y_max + visu->y_movement < 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

void		get_movement(t_visu *visu)
{
	visu->width = ft_abs(visu->x_max - visu->x_min);
	visu->height = ft_abs(visu->y_max - visu->y_min);
	if (visu->height == 0)
		visu->zoom_y = 1;
	else
		visu->zoom_y = 540.0 / (double)visu->height;
	if (visu->width == 0)
		visu->zoom_x = 1;
	else
		visu->zoom_x = 960.0 / (double)visu->width;
	visu->x_movement = (960 - (visu->width + 300) / 2 - visu->x_min) % 960;
	if (1920 - (visu->width + 100) < 0)
	{
		visu->x_movement = -visu->x_min;
		visu->zoom_x = 0.2;
	}
	visu->y_movement = (540 - (visu->height + 300) / 2 - visu->y_min) % 540;
	if (1080 - (visu->height + 100) < 0)
	{
		visu->y_movement = -visu->y_min;
		visu->zoom_y = 0.2;
	}
	check_values(visu);
}

void		set_point(int x, int y, t_point *point)
{
	point->x = x;
	point->y = y;
}

int			main(int argc, char **argv)
{
	t_organiser	organiser;
	t_visu		*visu;

	argv[0] = NULL;
	if (argc != 1)
		exit(0);
	if (ft_visu_validate(argv, &organiser) == -1)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	visu = init_visu(&organiser);
	visu->commands = ft_parse_commands();
	find_values(visu, &organiser);
	get_movement(visu);
	draw_field(visu, &organiser);
	ft_make_op(visu->win, visu);
	mlx_loop(visu->mlx);
	return (0);
}
