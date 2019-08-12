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

static void print_swap(t_graph *donor, t_graph *recipient)
{
	ft_putstr("L");
	ft_putstr(donor->name);
	ft_putstr("-");
	ft_putstr(recipient->name);
	ft_putstr(" ");
}

static void swap_start(t_graph *recipient, t_organiser *organiser)
{
	if (!recipient)
		return ;
	print_swap(organiser->start, recipient);
	organiser->ants_field++;
	organiser->ants--;
	recipient->ant = 1;
}

static void swap_ant(t_graph *donor, t_graph *recipient, t_organiser *organiser)
{
	if (!recipient)
		return ;
	print_swap(donor, recipient);
	if (recipient->end)
	{
		organiser->ants_field--;
		organiser->ants_end++;
		donor->ant = 0;
		return ;
	}
	donor->ant = 0;
	recipient->ant = 1;
}

static int down_is(t_list *down)
{
	t_graph *node;

	while (down)
	{
		node = down->content;
		if (!node->ant)
			return (1);
		down = down->next;
	}
	return (0);
}

static t_graph *search_recipient_this(t_list *this)
{
	t_graph *node;

	if (!this)
		return (NULL);
	while (this)
	{
		node = this->content;
		if (!node->ant && down_is(node->down))
			return (node);
		this = this->next;
	}
	return (NULL);
}

static t_graph *search_recipient(t_list *down, t_list *this)
{
	t_graph *recipient;
	t_graph *temp;
	t_list *down_temp;

	recipient = NULL;
	down_temp = down;
	while (down)
	{
		temp = down->content;
		if (!temp->ant)
		{
			recipient = temp;
			break ;
		}
		down = down->next;
	}
	if (!recipient)
		return (search_recipient_this(this));
	return (recipient);
}

static void jump(t_graph *node, t_organiser *organiser)
{
	size_t num_ants;
	t_list *down;
	t_list *this;
	t_graph *recipient;

	num_ants = organiser->ants_end + organiser->ants_field;
	if (!((node->start && organiser->ants) || node->ant))
		return ;
	down = node->down;
	this = node->this;
	while (node->start && organiser->ants && (recipient = search_recipient(down, this)))
		swap_start(recipient, organiser);
	if (!node->start)
		swap_ant(node, search_recipient(down, this), organiser);
}

static void to_right(t_list *level, size_t level_counter, t_organiser *organiser)
{
	t_graph *node;

	if (!level_counter)
		return ;
	while (level)
	{
		node = level->content;
		if (node->start || node->ant)
			jump(node, organiser);
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
	ft_putstr("\n");
	ft_putstr("\n");
	ants = organiser->ants;
	int y = 0;
	while (organiser->ants_end != ants)
	{
		to_start(organiser->end, organiser);
		ft_putstr("\n");
		if (y++ == 100)
			break ;
	}
}
