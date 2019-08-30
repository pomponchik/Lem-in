/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:09:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/30 22:45:35 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		algorithm(t_organiser *organiser)
{
	size_t	ants;
	char	*str;
	size_t	*lens;

	ants = organiser->ants;
	ft_putstr("\n");
	lens = NULL;
	while (organiser->ants_end != ants)
	{
		walking_ants(organiser, &lens);
		str = ft_strdup("\n");
		ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, 1));
	}
	free(lens);
	ft_lst_putstr_free_cs(ft_lst_turn(organiser->commands));
	free_ways(organiser->ways);
	ft_exit_adjacency(&(organiser->graph), &(organiser->size));
}
