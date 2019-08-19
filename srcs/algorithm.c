/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:09:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/11 22:09:14 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void print_swap(t_graph *donor, t_graph *recipient, t_organiser *organiser)
{
	char *str;

	str = ft_strjoin_free_2("L", ft_itoa(donor->ant_number));
	ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strjoin("-", recipient->name);
	ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strdup(" ");
	ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, ft_strlen(str)));
}

static void swap_ant(t_graph *donor, t_graph *recipient, t_organiser *organiser)
{
	if (!recipient)
		return ;
	print_swap(donor, recipient, organiser);
	if (recipient->end)
	{
		organiser->ants_field--;
		organiser->ants_end++;
		donor->ant = 0;
		return ;
	}
	donor->ant = 0;
	recipient->ant = 1;
	recipient->ant_number = donor->ant_number;
}

static void to_right(t_list *level, size_t level_counter, t_organiser *organiser)
{
	t_graph *node;

	if (!level_counter)
		return ;
	while (level)
	{
		node = level->content;
		if (!node->stop && !node->start && node->ant)
			swap_ant(node, search_recipient_usual(node, organiser), organiser);
		level = level->next;
	}
}

static void to_start(t_graph *level, t_organiser *organiser)
{
	size_t counter;

	counter = 0;
	while (level)
	{
		to_right(level->right, counter, organiser);
		counter++;
		level = level->up;
	}
}

void algorithm(t_organiser *organiser)
{
	size_t ants;
	char *str;

	ants = organiser->ants;
	ft_putstr("\n");
	organiser->commands = NULL;
	while (organiser->ants_end != ants)
	{
		to_start(organiser->end, organiser);
		swap_start(organiser);
		str = ft_strdup("\n");
		ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, 1));
	}
	ft_lst_putstr_free_cs(ft_lst_turn(organiser->commands));
	ft_exit_adjacency(&(organiser->graph), &(organiser->size));
}
