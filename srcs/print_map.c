/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:02:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/09/05 18:34:28 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_map(t_organiser *organizer)
{
	size_t	i;
	char	**line;

	i = 0;
	line = organizer->map;
	while (line[i])
	{
		ft_putstr(line[i]);
		ft_putchar('\n');
		i++;
	}
}
