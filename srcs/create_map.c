/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:45:52 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/05 18:50:35 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		create_map(t_organiser *organizer)
{
	char	*a;
	char	*b;
	char	*c;
	size_t	i;

	a = ft_strnew(0);
	c = ft_get_file(0, &i);
	b = ft_memjoin(c, i, a, 1);
	organizer->map = ft_strsplit(b, '\n');
	ft_strdel(&b);
	ft_strdel(&c);
	ft_strdel(&a);
}
