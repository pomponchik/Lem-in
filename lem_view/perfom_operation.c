/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfom_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:14:49 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/20 18:24:14 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu.h"

void	find_and_replace_graph(t_graph *graph, int ant_number, t_visu *visu)
{
	size_t	i;
	size_t	size;

	size = visu->organizer->size;
	i = 0;
	while (i < size)
	{
		if (graph[i].ant_number == ant_number)
		{
			graph[i].ant_number = 0;
			return ;
		}
		i++;
	}
	visu->organizer->ants = visu->organizer->ants - 1;
	return ;
}

int		insert_ant(t_visu *visu, size_t i, size_t j, int ant_num)
{
	size_t	counter;

	counter = 0;
	while (counter < visu->organizer->size)
	{
		if (ft_strncmp(((t_graph *)visu->organizer->graph)[counter].name,
				(char *)visu->commands->content + i, j) == 0)
		{
			((t_graph *)visu->organizer->graph)[counter].ant_number = ant_num;
			return (i + j);
		}
		counter++;
	}
	return (i + j);
}

int		pars_string(size_t i, char *c, t_visu *visu)
{
	int		ant_num;
	size_t	j;

	if (c[i] == ' ')
		i++;
	if (c[i] == 'L')
		i++;
	ant_num = ft_atoi(c + i);
	find_and_replace_graph(visu->organizer->graph, ant_num, visu);
	while (c[i] != '-')
		i++;
	i++;
	j = 0;
	while (c[i] != ' ' && c[i])
	{
		i++;
		j++;
	}
	i = i - j;
	return (insert_ant(visu, i, j, ant_num));
}

void	draw_finish(t_visu *visu)
{
	ft_bzero(visu->data, 2073600 * (visu->bits_per_pixel / 8));
	mlx_put_image_to_window(visu->mlx, visu->win, visu->img, 0, 0);
	mlx_string_put(visu->mlx, visu->win, 950,
			520, 0xFF0000, "    FINISH");
	mlx_string_put(visu->mlx, visu->win, 950,
			540, 0xFF0000, "Press esc to exit");
}

void	perfom_operation(t_visu *visu)
{
	size_t	i;
	t_list	*tmp;

	if (visu->commands == NULL)
	{
		draw_finish(visu);
		return ;
	}
	i = 0;
	while (((char *)(visu->commands->content))[i])
		i = pars_string(i, ((char *)(visu->commands->content)), visu);
	tmp = visu->commands;
	visu->commands = tmp->next;
	free(tmp->content);
	free(tmp);
	draw_field(visu, visu->organizer);
}
