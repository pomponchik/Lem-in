/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:09:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/21 20:39:09 by ahalmon-         ###   ########.fr       */
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

static void disstander(t_list *adjacency, t_graph *donor)
{
	t_graph *node;

	if (donor)
	{
		donor->stand = 0;
		donor->do_up = 1;
		donor->do_down = 1;
		donor->do_this = 1;
	}
	while (adjacency)
	{
		node = adjacency->content;
		node->stand = 0;
		node->stop = 0;
		adjacency = adjacency->next;
	}
}

void swap_ant(t_graph *donor, t_graph *recipient, t_organiser *organiser)
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
	if (donor->stand)
		disstander(donor->adjacency, donor);
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
	while (level && level->level <= organiser->level_start)
	{
		to_right(level->right, counter, organiser);
		counter++;
		level = level->up;
	}
}

void algorithm(t_organiser *organiser)
{
	size_t ants;
	t_list *previous;
	char *str;

	ants = organiser->ants;
	ft_putstr("\n");
	previous = NULL;
	while (organiser->ants_end != ants)
	{
		to_start(organiser->end, organiser);
		outers(organiser);
		swap_start(organiser);
		if (previous && previous == organiser->commands)
		{
			//printf("hhh\n");
			organiser->start->start = 0;
			disstander(organiser->excess, NULL);
		}
		else
		{
			str = ft_strdup("\n");
			ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, 1));
		}
		previous = organiser->commands;
		if (organiser->ants_end == 151 && organiser->ants_field == 1)
		{
			printf("ADJACENCY:\n");
			t_list	*lst = organiser->excess;
			while (lst)
			{
				if (((t_graph *)(lst->content))->ant)
				{
					printf("%zu, %d %d\n", ((t_graph *)(lst->content))->level, ((t_graph *)(lst->content))->stand, ((t_graph *)(lst->content))->stop);
					t_list	*adjacency = ((t_graph *)(lst->content))->adjacency;
					while (adjacency)
					{
						printf("%s %zu %d %d %d, ", ((t_graph *)(adjacency->content))->name, ((t_graph *)(adjacency->content))->level, ((t_graph *)(adjacency->content))->stop, ((t_graph *)(adjacency->content))->stand, ((t_graph *)(adjacency->content))->ant);
					/*	t_list	*adj = ((t_graph *)(adjacency->content))->adjacency;
						printf("(");
						while (adj)
						{

							printf("%s %zu %d %d", ((t_graph *)(adj->content))->name, ((t_graph *)(adj->content))->level, ((t_graph *)(adj->content))->stop, ((t_graph *)(adj->content))->stand);
							adj = adj->next;
						}
						printf("), ");*/
						adjacency = adjacency->next;
					}
					printf("\n");
				}

				lst = lst->next;
			}
		}
	}
	ft_lst_putstr_free_cs(ft_lst_turn(organiser->commands));
	ft_exit_adjacency(&(organiser->graph), &(organiser->size));
}
