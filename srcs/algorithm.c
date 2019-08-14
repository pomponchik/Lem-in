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

static void print_swap(t_graph *donor, t_graph *recipient, t_organiser *organiser)
{
	char *str;

	str = ft_strjoin_free_2("L", ft_itoa(donor->ant_number));
	ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strjoin("-", recipient->name);
	ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strdup(" ");
	ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, ft_strlen(str)));
}

static void swap_start(t_graph *recipient, t_organiser *organiser)
{
	if (!recipient)
		return ;
	print_swap(organiser->start, recipient, organiser);
	organiser->ants_field++;
	organiser->ants--;
	recipient->ant = 1;
	recipient->ant_number = (organiser->start)->ant_number;
	(organiser->start)->ant_number++;
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

//новая функция
static int is_less(t_list *arr, size_t ants)
{
	t_graph *node;

	while (arr)
	{
		node = arr->content;
		if (node->level <= ants)
			return (1);
		arr = arr->next;
	}
	return (0);
}

//новая функция
static t_graph *search_recipient_start(t_list *down, t_organiser *organiser)
{
	t_graph *node_temp;
	t_list *down_temp;
	int prove;
	t_graph *result;

	down_temp = down;
	result = NULL;
	while (down)
	{
		node_temp = down->content;
		prove = is_less(down_temp, organiser->ants);
		if ((organiser->ants > node_temp->level) && prove && !node_temp->ant)
		{
			if (result && result->level > node_temp->level)
				result = node_temp;
			else if (!result)
				result = node_temp;
		}
		else if (!prove && !node_temp->ant)
		{
			if (result && result->level > node_temp->level)
				result = node_temp;
			else if (!result)
				result = node_temp;
		}
		down = down->next;
	}
	return (result);
}

static t_graph *search_recipient(t_list *down, t_list *this, t_graph *node, t_organiser *organiser)
{
	t_graph *recipient;
	t_graph *temp;
	t_list *down_temp;

	//вызов новой функции
	if (node->start)
		return (search_recipient_start(down, organiser));
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
	while (node->start && organiser->ants && (recipient = search_recipient(down, this, node, organiser)))
		swap_start(recipient, organiser);
	if (!node->start)
		swap_ant(node, search_recipient(down, this, node, organiser), organiser);
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
	char *str;

	ants = organiser->ants;
	ft_putstr("\n");
	organiser->commands = NULL;
	while (organiser->ants_end != ants)
	{
		to_start(organiser->end, organiser);
		str = ft_strdup("\n");
		ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, 1));
	}
	ft_lst_putstr_free_cs(ft_lst_turn(organiser->commands));
	ft_exit_adjacency(&(organiser->graph), &(organiser->size));
}
