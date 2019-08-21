/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:52:40 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/18 20:52:42 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t prove_down_out(t_list *level, t_list *next_level, size_t level_num)
{
	free_chain_no_content(level);
	free_chain_no_content(next_level);
	return (level_num);
}

static size_t prove_down(t_list *level, size_t level_num, t_organiser *organiser)
{
	t_list *next_level;
	t_graph *node;
	t_list *level_temp;

	next_level = NULL;
	level_temp = level;

	while (level)
	{
		node = level->content;
		if (!node->start && !node->flag && !node->stop && !node->ant/* && !node->do_up*/)
			ft_lstadd(&next_level, ft_lstnew_no_copy(node, sizeof(t_graph)));
		if (!node->start && ((node->level <= organiser->level_start && !node->ant) || ((node->do_down || node->do_up || node->do_this) && !node->ant)))
			return (prove_down_out(level, next_level, level_num));
		node->flag = 1;
		level = level->next;
	}
	free_chain_no_content(level_temp);
	if (next_level)
	{
		return (prove_down(next_level, level_num + 1, organiser));
	}

	return (0);
}

size_t go_down(t_graph *node, t_organiser *organiser)
{
	t_list *temp;
	size_t result;

	temp = ft_lstnew_no_copy(node, sizeof(t_graph));
	result = prove_down(temp, 1, organiser);
	clean_excess(organiser);
	return (result);
}
