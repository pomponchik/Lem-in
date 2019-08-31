# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 07:18:31 by ahalmon-          #+#    #+#              #
#    Updated: 2019/08/31 20:37:36 by hlarson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re make all

FILENAMES = main_visu.c ft_make_op.c ft_check_num.c init_visu.c draw_line.c
FILENAMES += help_visu.c parse_commands.c ft_exit_adjacency.c ft_copy_name.c
FILENAMES += ft_make_adjacency.c ft_exit_checking.c draw_line_and_name.c
FILENAMES += ft_check_format_one.c ft_check_format_two.c ft_check_comment.c
FILENAMES += ft_check_adjacency.c free_chains.c put_first_adjacency.c 
FILENAMES += ft_visu_validate.c create_help.c count_num.c perfom_operation.c
FILENAMES += check_first_line.c create_graph_visu.c
NAME = visu

LIB = libft.a
LIB_PATH = Libft/

MINILIBX_PATH = minilibx_macos/

MLX_ADD = -L minilibx_macos -lmlx -framework OpenGL -framework Appkit

INCLUDES = includes

all: $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	make -C $(MINILIBX_PATH)
	gcc -Wall -Wextra -Werror $(FILENAMES) $(LIB_PATH)$(LIB) $(MLX_ADD)	-I $(INCLUDES) -o $(NAME)

clean:
	@$(MAKE) -sC $(LIB_PATH) clean
	@$(MAKE) -sC $(MINILIBX_PATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf *.dSYM
	rm -rf $(LIB_PATH)$(LIB)
	rm -rf $(MINILIBX_PATH)libmlx.a

re: fclean all
