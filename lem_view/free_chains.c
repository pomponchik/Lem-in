/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_chains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 22:29:14 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/20 18:08:37 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_chain_no_content(t_list *lst)
{
	t_list *temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}
