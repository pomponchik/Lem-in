/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:52:00 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/30 20:19:28 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	get_size(t_list *paths)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	tmp = paths;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void			fill_nums(size_t *nums, t_list *paths)
{
	t_list	*tmp;
	size_t	i;

	tmp = paths;
	i = 1;
	while (tmp)
	{
		nums[i] = tmp->content_size;
		i++;
		tmp = tmp->next;
	}
}

static	size_t		main_alg(size_t *nums, size_t *ants)
{
	size_t	i;
	size_t	j;
	size_t	counter;
	size_t	size;

	counter = 0;
	size = nums[0];
	i = 0;
	j = 0;
	nums++;
	while (i < nums[0])
	{
		if (nums[i] < nums[i + 1])
		{
			nums[i]++;
			while (j != 0)
			{
				nums[i - j] = nums[i - j] + 1;
				counter++;
				*ants = *ants - 1;
				if (*ants == 0)
					return (counter);
				j--;
			}
            counter++;
			*ants = *ants - 1;
			if (*ants == 0)
				return (counter);
			break ;
		}
		if (nums[i] == nums[i + 1])
		{
			j++;
			i++;
		}
	}
	if (j != 0)
		counter = j;
	return (counter);
}

size_t			get_num_path(t_list *paths, size_t **nums, size_t ants)
{
	size_t	previous_counter;
	size_t	new_counter;

	if (!ants)
		return (0);
	if (!(*nums))
	{
		*nums = (size_t *)malloc(sizeof(size_t) * (get_size(paths) + 1));
		*nums[0] = get_size(paths);
	}
	fill_nums(*nums, paths);
	if (*nums[0] == 1)
		return (1);
	previous_counter = 0;
	while (ants != 0)
	{
		new_counter = main_alg(*nums, &ants);
		if (new_counter > previous_counter)
			previous_counter = new_counter;
	}
	printf("%d\n", previous_counter);
	return (previous_counter);
}
