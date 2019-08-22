/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:45:59 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/22 20:46:00 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void print_swap(t_graph *donor, t_graph *recipient, t_organiser *organiser)
{
	char *str;

	str = ft_strjoin_free_2("L", ft_itoa(donor->ant_number));
	ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strjoin("-", recipient->name);
	ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, ft_strlen(str)));
	str = ft_strdup(" ");
	ft_lstadd(&((*organiser).commands), ft_lstnew_no_copy(str, ft_strlen(str)));
}
