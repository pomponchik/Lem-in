/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:41:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/13 19:40:23 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	if (destptr == (void *)srcptr)
		return ((void *)srcptr);
	while (num)
	{
		((char *)destptr)[num - 1] = ((char *)srcptr)[num - 1];
		num--;
	}
	return (destptr);
}
