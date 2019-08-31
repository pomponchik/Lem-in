/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:50:14 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/20 13:35:29 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu.h"

static	t_list	*copy_command(char *line)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->content = ft_strdup(line);
	tmp->content_size = sizeof(char);
	tmp->next = NULL;
	ft_strdel(&line);
	return (tmp);
}

t_list		*ft_parse_commands(void)
{
	char	*line;
	t_list	*tmp;
	t_list	*head;

	tmp = NULL;
	if (get_next_line(0, &line) > 0)
		tmp = copy_command(line);
	head = tmp;
	while (get_next_line(0 , &line) > 0)
	{
		tmp->next = copy_command(line);
		tmp = tmp->next;
	}
	tmp = NULL;
	ft_strdel(&line);
	return (head);
}
