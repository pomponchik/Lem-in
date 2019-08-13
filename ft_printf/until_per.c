/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 21:10:18 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/13 19:24:52 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fillit_color(t_print **print, int j)
{
	j = 0;
	while (j <= 8 && (*print)->copy[(*print)->i + j] != '%'
			&& (*print)->copy[(*print)->i + j] != '\0')
	{
		if (((*print)->copy[(*print)->i + j]) != '}')
			(*print)->color[j] = (*print)->copy[(*print)->i + j];
		else
		{
			(*print)->color[j] = (*print)->copy[(*print)->i + j];
			break ;
		}
		j++;
	}
	return (j);
}

char	*fillit_str_color(t_print **print, int *i, char *str, int j)
{
	if (ft_color_print(*print) == 1)
		while (PF_RED[j])
			str[(*i)++] = PF_RED[j++];
	else if (ft_color_print(*print) == 2)
		while (PF_GREEN[j])
			str[(*i)++] = PF_GREEN[j++];
	else if (ft_color_print(*print) == 3)
		while (PF_YELLOW[j])
			str[(*i)++] = PF_YELLOW[j++];
	else if (ft_color_print(*print) == 4)
		while (PF_BLUE[j])
			str[(*i)++] = PF_BLUE[j++];
	else if (ft_color_print(*print) == 5)
		while (PF_PURPLE[j])
			str[(*i)++] = PF_PURPLE[j++];
	else if (ft_color_print(*print) == 6)
		while (PF_CYAN[j])
			str[(*i)++] = PF_CYAN[j++];
	else if (ft_color_print(*print) == 7)
		while (PF_EOC[j])
			str[(*i)++] = PF_EOC[j++];
	if (ft_color_print(*print))
		((*print)->i) += ft_strlen((*print)->color);
	ft_bzero((*print)->color, 9);
	return (str);
}

int		len_str_until_per(t_print **print, int *len_copy, int i)
{
	int	j;

	*len_copy = 0;
	while ((*print)->copy[(*print)->i] != '%'
	&& (*print)->copy[(*print)->i] != '\0')
	{
		if ((*print)->copy[(*print)->i] == '{')
		{
			j = fillit_color(print, 0);
			if (ft_color_print(*print))
				if (ft_color_print(*print) != 7)
					i += ft_strlen(PF_RED) - 1;
				else
					i += ft_strlen(PF_EOC) - 1;
			else
				i += j - 1;
			(*print)->i += j;
			(*len_copy) += j;
			ft_bzero((*print)->color, 9);
		}
		i++;
		(*len_copy)++;
		((*print)->i)++;
	}
	return (i);
}

char	*end_str(t_print **print, char *str)
{
	int i;

	i = 0;
	while ((*print)->copy[(*print)->i] != '%'
			&& (*print)->copy[(*print)->i] != '\0')
	{
		if ((*print)->copy[(*print)->i] == '{')
		{
			fillit_color(print, 0);
			fillit_str_color(print, &i, str, 0);
		}
		if ((*print)->copy[(*print)->i] != '%'
				&& (*print)->copy[(*print)->i] != '\0')
		{
			fillit_color(print, 0);
			if (ft_color_print(*print))
				fillit_str_color(print, &i, str, 0);
			else
				str[i++] = (*print)->copy[((*print)->i)++];
		}
	}
	return (str);
}

char	*ft_until_per(t_print **print)
{
	int		len_copy;
	char	*str;

	str = ft_strnew(len_str_until_per(print, &len_copy, 0));
	((*print)->i) = ((*print)->i) - len_copy;
	return (end_str(print, str));
}
