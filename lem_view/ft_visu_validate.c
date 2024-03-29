/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 21:39:36 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/22 02:25:58 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visu.h"

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
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (n);
}

size_t		ft_get_ant_num(int k, char **line)
{
	int	n;

	n = 0;
	while (get_next_line(k, line) > 0)
	{
		if (*line[0] == '#')
		{
			if (ft_check_comment_ant(*line) < 0)
				return (0);
		}
		else
		{
			n = get_ant_num(*line);
			if (n < 0)
				return (0);
			return (n);
		}
	}
	return (0);
}

int			ft_get_basic_coord(int k, char **line, t_help **help)
{
	int	start;
	int	end;
	int	l;

	start = 0;
	end = 0;
	while (get_next_line(k, line) > 0)
	{
		if (*line[0] == '#')
		{
			if (ft_check_comment(*line, help, &start, &end) < 0)
				return (-1);
		}
		else
		{
			if ((l = ft_check_format_one(help, *line, &start, &end)) < 0)
				return (-1);
			if (l == 1)
				return (0);
		}
	}
	return (-1);
}

int			ft_get_adjacency(char **line, t_graph **graph, int k, size_t *count)
{
	while (get_next_line(k, line) > 0)
	{
		if (ft_strcmp(*line, "") == 0)
		{
			ft_strdel(line);
			return (0);
		}
		if (*line[0] == '#')
		{
			if (ft_check_comment_ant(*line) < 0)
				return (-1);
		}
		else
		{
			if ((ft_make_adjacency(*line, graph, count)) < 0)
				return (-1);
		}
	}
	return (0);
}

int			ft_visu_validate(char **argv, t_organiser *organiser)
{
	int		k;
	char	*line;
	t_help	*help;
	t_graph *asd;
	size_t	count;

	argv[0] = NULL;
	k = 0;
	help = NULL;
	line = NULL;
	organiser->ants = ft_get_ant_num(k, &line);
	if (organiser->ants == 0)
		return (-1);
	if (ft_get_basic_coord(k, &line, &help) == -1)
		return (-1);
	asd = create_graph_visu(help, &count, organiser);
	put_first_adjacency(line, &asd, count);
	if (ft_get_adjacency(&line, &asd, k, &count) == -1)
		return (-1);
	ft_strdel(&line);
	if (ft_check_adjacency(asd, count) < 0)
		return (ft_exit_adjacency(&asd, &count));
	organiser->graph = (asd);
	return (0);
}
