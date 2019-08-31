/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:52:00 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/31 21:02:10 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t		get_size(t_list *paths)
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

static size_t		increment_previous(size_t *nums, size_t *ants,
					size_t i, size_t *j)
{
	size_t	counter;

	counter = 0;
	while (*j != 0)
	{
		nums[i - *j] = nums[i - *j] + 1;
		counter++;
		*ants = *ants - 1;
		if (*ants == 0)
			return (counter);
		*j = *j - 1;
	}
	return (counter);
}

static	size_t		main_alg(size_t *nums, size_t *ants, size_t i)
{
	size_t	j;
	size_t	counter;

	counter = 0;
	j = 0;
	while (i < nums[0])
	{
		if (nums[i] < nums[i + 1])
		{
			nums[i]++;
			counter = counter + increment_previous(nums, ants, i, &j);
			if (*ants == 0)
				return (counter);
			counter++;
			*ants = *ants - 1;
			return (counter);
		}
		if (nums[i] == nums[i + 1])
		{
			j++;
			i++;
		}
	}
	return ((j == 0) ? counter : j);
}

size_t				get_num_path(t_list *paths, size_t **nums, size_t ants)
{
	size_t	previous_counter;
	size_t	new_counter;
	size_t	size;

	size = get_size(paths);
	if (!ants)
		return (0);
	if (!(*nums))
	{
		*nums = (size_t *)malloc(sizeof(size_t) * (size + 1));
		*nums[0] = size;
	}
	fill_nums(*nums, paths);
	if (*nums[0] == 1)
		return (1);
	previous_counter = 0;
	while (ants != 0)
	{
		new_counter = main_alg(*nums, &ants, 1);
		if (new_counter > previous_counter)
			previous_counter = new_counter;
		if (previous_counter == size - 1)
			break ;
	}
	return (previous_counter);
}
