/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:47:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/26 05:58:05 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../Libft/includes/libft.h"
# include <stdio.h>

typedef struct		s_graph
{
    char			*name;
    int				ant_number;
    struct s_graph	 *adjacency;
    char			start;
    char			end;
    int				x;
    int				y;
}					t_graph;

typedef struct		s_help
{
    char			*name;
    struct s_help	*next;
    char			start;
    char			end;
    int				x;
    int				y;
}					t_help;

int					ft_check_comment(char *line, t_help **help, int *start, int *end);
int                 ft_check_comment_ant(char *line);
int					ft_check_format_one(t_help **help, char *line, int *start, int *end);
int                 check_first_line(char *line, t_help *help);
t_graph				**create_graph(t_help *help, int n);
int					ft_validate(t_graph ***graph, char **argv);
int					count_num(int k);
t_help				*create_help(int *start, int *end);
void                add_help(t_help *tmp, t_help *help);
char				*ft_copy_name(char *line, int i);
void                put_first_adjacency(char *line, t_graph **graph);
int                 ft_make_adjacency(char *line, t_graph **graph);
int		            ft_exit_checking(char **line, t_help **help);
int                 ft_exit_adjacency(t_graph **graph);
int                 ft_exit_adjacency_norm(char *c, char *line);
int                 ft_exit_adjacency_error(char *c, char *line, t_graph **graph);
int                 ft_exit_adjacency_error_two(char *line, t_graph **graph);

#endif
