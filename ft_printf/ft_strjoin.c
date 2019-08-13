/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 01:36:58 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/13 19:33:43 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size_1;

	if (!s1 || !s2)
		return (NULL);
	size_1 = ft_strlen(s1);
	if (!(result = (char *)malloc(size_1 + ft_strlen(s2) + 1)))
		return (NULL);
	ft_memcpy(result, s1, size_1 + 1);
	return (ft_strcat(result, s2));
}
