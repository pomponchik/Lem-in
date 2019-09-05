/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:47:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/09/05 18:48:12 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../Libft/includes/libft.h"
# include <stdio.h>

typedef struct		s_graph
{
	char			*name;
	char			ant;
	int				ant_number;
	t_list			*adjacency;
	char			start;
	char			end;
	char			flag;
	int				x;
	int				y;
	struct s_graph	*parent;
	char			stop;
	size_t			index;
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

typedef struct		s_organiser
{
	t_graph			*graph;
	size_t			size;
	size_t			ants;
	size_t			ants_field;
	size_t			ants_end;
	t_graph			*start;
	t_graph			*end;
	t_list			*commands;
	t_list			*ways;
	size_t			short_way;
	char			**map;
}					t_organiser;

int					ft_check_comment(char *line, t_help **help, \
	int *start, int *end);
int					ft_check_comment_ant(char *line);
int					ft_check_format_one(t_help **help, \
	char *line, int *start, int *end);
int					check_first_line(char *line, t_help *help);
t_graph				*create_graph(t_help *help, \
	size_t *count, t_organiser *organiser);
int					ft_validate(t_organiser *organiser);
int					count_num(int k);
t_help				*create_help(int *start, int *end);
void				add_help(t_help *tmp, t_help *help);
char				*ft_copy_name(char *line, int i);
void				put_first_adjacency(char *line, \
	t_graph **graph, size_t count);
int					ft_make_adjacency(char *line, \
	t_graph **graph, size_t *count);
int					ft_exit_checking(t_help **help);
int					ft_exit_adjacency_norm(char *c);
int					ft_exit_adjacency_error(char *c, \
	t_graph **graph, size_t *count);
int					ft_exit_adjacency_error_two(\
	t_graph **graph, size_t *count);
int					arg_equal_one(void);
int					ft_check_num(t_help *help, t_help *tmp);
int					main_error();
int					ft_check_adjacency(t_graph *graph, size_t count);
int					ft_exit_adjacency(t_graph **graph, size_t *count);
int					help_check_line(char *c, t_help *tmp);
void				free_chain(t_list *lst);
void				algorithm(t_organiser *organiser);
void				print_map(t_organiser *organiser);
void				print_swap(t_graph *donor, \
	t_graph *recipient, t_organiser *organiser);
void				swap(t_graph *donor, t_graph *recipient, \
	t_organiser *organiser, size_t way_size);
void				bfs(t_organiser *organiser);
void				no_ways(t_graph **graph, size_t *count);
void				one_way(t_graph **graph, size_t *count);
t_list				*list_copy(t_list *lst, t_graph *parent);
void				disflagger(t_graph *nodes, size_t count);
void				walking_ants(t_organiser *organiser, size_t **lens);
void				no_way(t_graph **graph, size_t *count);
void				stopper(t_list *way);
size_t				get_num_path(t_list *paths, size_t **nums, size_t ant);
void				free_ways(t_list *ways);
int					one_to_one(t_organiser *organiser);
void				print_file(char *filename);
void				swap_start(t_graph *recipient, \
	t_organiser *organiser, size_t go);
void				print_map(t_organiser *organizer);
void				ft_del_map(t_organiser *organizer);

#endif
