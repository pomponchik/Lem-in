/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:27:15 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/20 18:21:33 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "../minilibx_macos/mlx.h"
# include "lem_in.h"

typedef struct	s_visu
{
	void		*win;
	void		*mlx;
	void		*img;
	char		*data;
	int			bits_per_pixel;
	int			endian;
	int			size_line;
	double		zoom_x;
	double		zoom_y;
	long		width;
	long		height;
	int			x_movement;
	int			y_movement;
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	t_list		*commands;
	t_organiser	*organizer;
}				t_visu;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

void			draw_line(t_point one, t_point two, t_visu *visu, int color);
void			find_values(t_visu *visu, t_organiser *organizer);
void			ft_make_op(void *win_ptr, t_visu *visu);
t_visu			*init_visu(t_organiser *organizer);
void			draw_field(t_visu *visu, t_organiser *organiser);
void			set_point(int x, int y, t_point *point);
t_list			*ft_parse_commands(void);
int				ft_visu_validate(char **argv, t_organiser *organizer);
t_graph			*create_graph_visu(t_help *help, size_t *count,
				t_organiser *organiser);
void			perfom_operation(t_visu *visu);


#endif
