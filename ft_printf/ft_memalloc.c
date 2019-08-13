/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:50:17 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/10 21:22:03 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*new_mem;
	size_t	i;

	i = 0;
	new_mem = malloc(size);
	if (new_mem)
	{
		while (i < size)
		{
			((unsigned char *)new_mem)[i] = 0;
			i++;
		}
		return (new_mem);
	}
	else
		return (NULL);
}
