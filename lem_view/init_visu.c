/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:35:31 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/22 02:02:21 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu.h"

t_visu	*init_visu(t_organiser *organiser)
{
	t_visu	*visu;

	visu = (t_visu *)malloc(sizeof(t_visu));
	visu->mlx = mlx_init();
	visu->win = mlx_new_window(visu->mlx, 1920, 1080, "Lem_in");
	visu->img = mlx_new_image(visu->mlx, 1920, 1080);
	visu->data = mlx_get_data_addr(visu->img, &(visu->bits_per_pixel), &(visu->size_line), &(visu->endian));
	printf("HIIIIIIIIII\n");
	visu->x_min = ((t_graph *)organiser->graph)[0].x;
	printf("HIIIIIIIIII\n");
	visu->y_min = ((t_graph *)organiser->graph)[0].y;
	visu->x_max = ((t_graph *)organiser->graph)[0].x;;
	visu->y_max = ((t_graph *)organiser->graph)[0].y;
	visu->organizer = organiser;
	return (visu);
}
