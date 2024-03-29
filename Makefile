# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 07:18:31 by ahalmon-          #+#    #+#              #
#    Updated: 2019/09/05 18:46:41 by hlarson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re make all

FILENAMES = main.c
FILENAMES += arg.c check_first_line.c count_num.c
FILENAMES += create_graph.c create_help.c ft_check_adjacency.c
FILENAMES += ft_check_comment.c ft_check_format_one.c ft_check_num.c
FILENAMES += ft_copy_name.c ft_exit_adjacency.c ft_exit_checking.c
FILENAMES += ft_make_adjacency.c ft_validate.c stopper.c
FILENAMES += put_first_adjacency.c ft_check_format_two.c free_chain.c
FILENAMES += algorithm.c list_copy.c swap.c bfs.c
FILENAMES += disflagger.c no_ways.c walking_ants.c print_swap.c
FILENAMES += get_num_path.c print_file.c one_to_one.c print_map.c
FILENAMES += ft_delete_map.c create_map.c
NAME = lem-in

SRCS	=$(addprefix srcs/, $(FILENAMES))
OBJS	=$(addprefix build/, $(FILENAMES:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I includes/
LFLAGS	= -L ./Libft/ -lft

all: $(NAME)

$(NAME):$(OBJS) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS)

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./Libft
	@make -C ./lem_view
	@make clean -C ./Libft
	@make clean -C ./lem_view

clean:
	@rm -rf build/

fclean: clean
	@make fclean -C ./Libft
	@make fclean -C ./lem_view
	@rm -f $(NAME)

build:
	@mkdir build/
