# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazurok <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 11:59:18 by amazurok          #+#    #+#              #
#    Updated: 2018/03/23 16:46:32 by amazurok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH = checker

NAME_PS = push_swap

SRC_SRC = ./src/ft_comp_sort.c ./src/ft_del_data.c ./src/ft_del_elem.c ./src/ft_error.c \
			./src/ft_in_list.c ./src/ft_issort.c ./src/ft_new_list.c ./src/ft_push.c \
			./src/ft_read_arg.c ./src/ft_rotate.c ./src/ft_steklen.c ./src/ft_swap.c \
			./src/ft_dstr.c

SRC_PS = ./push/ft_ad_func.c ./push/ft_med.c ./push/ft_mod_cmd.c ./push/ft_sort.c \
			./push/ft_sort_a.c ./push/ft_sort_b.c ./push/main.c

SRC_CH = ./check/ft_new_c_key.c ./check/ft_print_stek.c ./check/ft_read_key.c ./check/ft_set_cmd.c \
			./check/ft_usage_help.c ./check/ft_valid_cmd.c ./check/t_main.c

#OBJ_PS = $(patsubst %.c, %.o, $(SRC_SRC)) $(patsubst %.c, %.o, $(SRC_PS))

#OBJ_CH = $(patsubst %.c, %.o, $(SRC_SRC)) $(patsubst %.c, %.o, $(SRC_CH)) 

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

all: $(NAME_CH) $(NAME_PS) 
	
$(NAME_CH): $(SRC_CH) $(SRC_SRC)
	$(MLIB) 
	gcc -Wall -Wextra -Werror $(SRC_SRC) $(SRC_CH) $(LIB) -o $(NAME_CH)

$(NAME_PS): $(SRC_PS) $(SRC_SRC)
	$(MLIB) 
	gcc -Wall -Wextra -Werror $(SRC_SRC) $(SRC_PS) $(LIB) -o $(NAME_PS)

%.o : %.c
	gcc -c -Wall -Wextra -Werror $<
	
clean:
	rm -f $(OBJ)
	$(MLIB) clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CH)
	$(MLIB) fclean

re: fclean all