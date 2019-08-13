/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 00:17:40 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/11 16:39:59 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == (size_t)-1)
		return (NULL);
	str = malloc(sizeof(char) * size + 1);
	if (str)
		ft_bzero(str, size + 1);
	else
		return (NULL);
	return (str);
}
