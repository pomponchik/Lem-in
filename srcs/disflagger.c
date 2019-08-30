/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disflagger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:36:22 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/30 22:36:54 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		disflagger(t_graph *nodes, size_t count)
{
	size_t	index;

	index = 0;
	while (index < count)
	{
		(&(nodes[index]))->flag = 0;
		index++;
	}
}
