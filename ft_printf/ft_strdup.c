/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:12:09 by rpizpot           #+#    #+#             */
/*   Updated: 2019/04/10 21:37:08 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (s)
	{
		while (str[i])
		{
			s[i] = str[i];
			i++;
		}
		s[i] = '\0';
		return (s);
	}
	else
	{
		free(s);
		return (NULL);
	}
}
