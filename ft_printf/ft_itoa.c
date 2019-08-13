/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:44:51 by hlarson           #+#    #+#             */
/*   Updated: 2019/07/10 19:45:00 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	int			i;
	char		*numb;
	int			flag;
	long int	k;

	k = (long int)n;
	flag = 0;
	if (k < 0)
	{
		flag = 1;
		k *= -1;
	}
	i = ft_size(k);
	numb = (char *)malloc(sizeof(char) * i + 1 + flag);
	if (!numb)
		return (NULL);
	if (flag == 1)
		numb[0] = '-';
	numb[i + flag] = '\0';
	while (i-- > 0)
	{
		numb[i + flag] = k % 10 + '0';
		k = k / 10;
	}
	return (numb);
}
