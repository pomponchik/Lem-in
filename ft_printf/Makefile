# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlarson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 16:48:42 by hlarson           #+#    #+#              #
#    Updated: 2019/08/01 18:43:49 by rpizpot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

SRCS = buf_right_alignment.c buffer.c count_numbers.c ft_atoi_precision.c ft_atoi_width.c ft_bzero.c ft_color_print.c ft_count_until.c ft_create_str.c ft_float.c ft_hex.c ft_int.c ft_itoa.c ft_long_composition.c ft_long_composition_dot.c ft_long_division.c ft_long_double.c ft_long_pow.c ft_long_pow_minus.c ft_long_sum.c ft_long_sum_dot.c ft_make_precision.c ft_memalloc.c ft_minus_str.c ft_octal.c ft_one.c ft_printf.c ft_remake_str.c ft_size.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strnew_one.c ft_strnew_zero.c ft_strrjoin.c ft_type_e.c ft_type_e_l.c ft_unsigned_int.c ft_zero.c get_after_dot_float.c get_before_dot_float.c inicialization.c parser.c parser_flag.c parser_size.c parser_type.c print_percent.c print_w_flag.c reinicialization.c until_per.c what_print.c ft_point.c ft_char.c ft_help_with_precision.c buffer_2.c norm_buffer.c

OUT = buf_right_alignment.o buffer.o count_numbers.o ft_atoi_precision.o ft_atoi_width.o ft_bzero.o ft_color_print.o ft_count_until.o ft_create_str.o ft_float.o ft_hex.o ft_int.o ft_itoa.o ft_long_composition.o ft_long_composition_dot.o ft_long_division.o ft_long_double.o ft_long_pow.o ft_long_pow_minus.o ft_long_sum.o ft_long_sum_dot.o ft_make_precision.o ft_memalloc.o ft_minus_str.o ft_octal.o ft_one.o ft_printf.o ft_remake_str.o ft_size.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strjoin.o ft_strlen.o ft_strnew.o ft_strnew_one.o ft_strnew_zero.o ft_strrjoin.o ft_type_e.o ft_type_e_l.o ft_unsigned_int.o ft_zero.o get_after_dot_float.o get_before_dot_float.o inicialization.o parser.o parser_flag.o parser_size.o parser_type.o print_percent.o print_w_flag.o reinicialization.o until_per.o what_print.o ft_point.o ft_char.o ft_help_with_precision.o buffer_2.o norm_buffer.o

INCLUDES = ft_printf.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c -g $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all
