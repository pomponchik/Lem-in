/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:34:37 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/05 18:41:48 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_del_map(t_organiser *organizer)
{
	size_t	i;
	char	**line;

	i = 0;
	line = organizer->map;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}
