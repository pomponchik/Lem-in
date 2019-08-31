/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 21:28:46 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/10 21:33:58 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		help_check_line(char *line, t_help *tmp)
{
	if (check_first_line(line, tmp) == -1)
		return (ft_exit_checking(&line, &tmp));
	return (1);
}
