/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 21:39:36 by hlarson           #+#    #+#             */
/*   Updated: 2019/09/05 18:47:46 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_ant_num(char *line)
{
	int		n;
	int		i;

	i = 0;
	n = ft_atoi(line);
	if (line[i] == '-')
		i++;
	if (line[i] < '0' || line[i] > '9')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (count_num(n) != i || line[i] != '\0')
	{
		return (-1);
	}
	return (n);
}

size_t		ft_get_ant_num(char **line, size_t *count_map)
{
	int	n;

	n = 0;
	while (line[*count_map])
	{
		if (line[*count_map][0] == '#')
		{
			if (ft_check_comment_ant(line[*count_map]) < 0)
				return (0);
			*count_map = *count_map + 1;
		}
		else
		{
			n = get_ant_num(*line);
			*count_map = *count_map + 1;
			if (n < 0)
				return (0);
			return (n);
		}
	}
	return (0);
}

int			ft_get_basic_coord(char **line, size_t *count_map, t_help **help)
{
	int	start;
	int	end;
	int	l;

	start = 0;
	end = 0;
	while (line[*count_map] > 0)
	{
		if (line[*count_map][0] == '#')
		{
			if (ft_check_comment(line[*count_map], help, &start, &end) < 0)
				return (-1);
		}
		else
		{
			if ((l = ft_check_format_one(help,
							line[*count_map], &start, &end)) < 0)
				return (-1);
			if (l == 1)
				return (0);
		}
		*count_map = *count_map + 1;
	}
	return (-1);
}

int			ft_get_adjacency(char **line, size_t *count_map,
			t_graph **graph, size_t *count)
{
	while (line[*count_map] > 0)
	{
		if (line[*count_map][0] == '#')
		{
			if (ft_check_comment_ant(line[*count_map]) < 0)
				return (-1);
		}
		else
		{
			if ((ft_make_adjacency(line[*count_map], graph, count)) < 0)
				return (-1);
		}
		*count_map = *count_map + 1;
	}
	return (0);
}

int			ft_validate(t_organiser *organiser)
{
	size_t	count_map;
	t_help	*help;
	t_graph *asd;
	size_t	count;

	count_map = 0;
	create_map(organiser);
	help = NULL;
	organiser->ants = ft_get_ant_num(organiser->map, &count_map);
	if (organiser->ants == 0)
		return (-1);
	if (ft_get_basic_coord(organiser->map, &count_map, &help) == -1)
		return (-1);
	asd = create_graph(help, &count, organiser);
	if (ft_get_adjacency(organiser->map, &count_map, &asd, &count) == -1)
		return (-1);
	if (ft_check_adjacency(asd, count) < 0)
		return (ft_exit_adjacency(&asd, &count));
	organiser->graph = (asd);
	return (0);
}
