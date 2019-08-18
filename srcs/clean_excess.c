/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_excess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:47:03 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/18 20:47:05 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void clean_excess(t_organiser *organiser)
{
	t_list *excess;
	t_graph *node;

	excess = organiser->excess;
	while (excess)
	{
		node = excess->content;
		node->flag = 0;
		excess = excess->next;
	}
}
