/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:47:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/08/13 20:12:03 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../Libft/includes/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct		s_graph
{
    char			*name;
	char			ant;
    int				ant_number;
    t_list	        *adjacency;
	struct s_graph	*up;
	t_list	        *down;
	t_list	        *right;
	t_list	        *this;
	t_list	        *start_up;
    char			start;
    char			end;
	char			flag;
	char			stop;
    int				x;
    int				y;
	size_t			level;
	size_t			excess_level;
	char			do_up;
	char			do_down;
	char			do_this;
	char			stand;
	char			unmove;
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
	t_list	        *commands;
	t_list			*excess;
	t_list			*sorted;
	size_t			level_start;
}					t_organiser;

int					ft_check_comment(char *line, t_help **help, int *start, int *end);
int                 ft_check_comment_ant(char *line);
int					ft_check_format_one(t_help **help, char *line, int *start, int *end);
int                 check_first_line(char *line, t_help *help);
t_graph				*create_graph(t_help *help, size_t *count, t_organiser *organiser);
int					ft_validate(char **argv, t_organiser *organiser);
int					count_num(int k);
t_help				*create_help(int *start, int *end);
void                add_help(t_help *tmp, t_help *help);
char				*ft_copy_name(char *line, int i);
void                put_first_adjacency(char *line, t_graph **graph, size_t count);
int                 ft_make_adjacency(char *line, t_graph **graph, size_t *count);
int		            ft_exit_checking(char **line, t_help **help);
int                 ft_exit_adjacency_norm(char *c, char *line);
int                 ft_exit_adjacency_error(char *c, char *line, t_graph **graph, size_t *count);
int                 ft_exit_adjacency_error_two(char *line, t_graph **graph, size_t *count);
int                 arg_equal_one(void);
int                 ft_check_num(t_help *help, t_help *tmp);
int                 main_error();
int                 ft_check_adjacency(t_graph *graph, size_t count);
int                 ft_exit_adjacency(t_graph **graph, size_t *count);
int					help_check_line(char *c, t_help *tmp);
void first_bfs(t_graph *graph, size_t count, t_graph *finish, t_organiser *organiser);
void free_chain_no_content(t_list *lst);
t_list *list_copy_without_flag(t_list *lst);
t_list *list_copy_without_flag_2(t_list *lst);
void building_connections(t_organiser *organiser);
void disflagger_first(t_graph *graph, size_t count);
void disflagger_second(t_graph *graph, size_t count, size_t level_start);
void disflagger_base(t_graph *graph, size_t count);
void algorithm(t_organiser *organiser);
void	print_map(t_organiser *organiser);
int dijkstra_prove(t_graph *node);
void clean_excess(t_organiser *organiser);
size_t go_down(t_graph *node, t_organiser *organiser);
void replacing_links_start(t_graph *start);
t_graph *search_recipient_start(t_graph *start, t_organiser *organiser);
void print_swap(t_graph *donor, t_graph *recipient, t_organiser *organiser);
void swap_start(t_organiser *organiser);
int down_is(t_list *down);
t_graph *search_recipient_usual(t_graph *node, t_organiser *organiser);
t_list *excess_filler(t_graph *graph, size_t size, size_t level_start);
t_graph *search_recipient_over_do(t_graph *node);
t_graph *search_recipient_over(t_graph *node, t_organiser *organiser);
void outers(t_organiser *organiser);
t_list *insert_in_sorted(t_list *sorted, t_graph *node);
void swap_ant(t_graph *donor, t_graph *recipient, t_organiser *organiser);
void flags_to_stop(t_list *adjacency);

#endif
