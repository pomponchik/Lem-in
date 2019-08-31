/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_and_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:37:48 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/20 18:11:18 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu.h"

static void	draw_lines(t_visu *visu, t_organiser *organizer, t_graph *graph)
{
	size_t	i;
	t_list	*adjacency;
	t_graph	*tmp;
	t_point	one;
	t_point	two;

	i = 0;
	while (i != organizer->size)
	{
		adjacency = graph[i].adjacency;
		while (adjacency)
		{
			tmp = adjacency->content;
			set_point(graph[i].x * visu->zoom_x + visu->x_movement,
					graph[i].y * visu->zoom_y + visu->y_movement, &one);
			set_point(visu->zoom_x * tmp->x + visu->x_movement,
					visu->zoom_y * tmp->y + visu->y_movement, &two);
			draw_line(one, two, visu, 0x808080);
			adjacency = adjacency->next;
		}
		i++;
	}
}

static void	draw_names(t_visu *visu, t_organiser *organizer, t_graph *graph)
{
	size_t	i;

	i = 0;
	while (i != organizer->size)
	{
		if (graph[i].ant_number == 0)
			mlx_string_put(visu->mlx, visu->win,
					visu->zoom_x * graph[i].x + visu->x_movement,
					visu->zoom_y * graph[i].y + visu->y_movement,
					0x808080, graph[i].name);
		if (graph[i].start == 1 || graph[i].end == 1)
			mlx_string_put(visu->mlx, visu->win,
					visu->zoom_x * graph[i].x + visu->x_movement,
					visu->zoom_y * graph[i].y + visu->y_movement,
					0xFF0000, graph[i].name);
		else if (graph[i].ant_number != 0)
			mlx_string_put(visu->mlx, visu->win,
					visu->zoom_x * graph[i].x + visu->x_movement,
					visu->zoom_y * graph[i].y + visu->y_movement,
					0xFF000, graph[i].name);
		i++;
	}
}

void		draw_field(t_visu *visu, t_organiser *organizer)
{
	t_graph	*graph;

	graph = organizer->graph;
	draw_lines(visu, organizer, graph);
	mlx_put_image_to_window(visu->mlx, visu->win, visu->img, 0, 0);
	draw_names(visu, organizer, graph);
}
