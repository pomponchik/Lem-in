/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:14:38 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/31 17:27:36 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_file(char *filename)
{
	size_t	size;
	void	*to_print;

	to_print = ft_get_file(filename, &size);
	if (size && to_print)
		write(1, to_print, size);
	free(to_print);
}
