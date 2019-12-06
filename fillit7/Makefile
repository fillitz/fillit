# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 16:21:19 by kcharlet          #+#    #+#              #
#    Updated: 2019/11/28 16:21:24 by kcharlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCL = -I ./includes/ 
INCL_LIB = ./libft/libft.a
OBJS = main.o ft_array_functions.o ft_print_functions.o \
		extraction_of_tetrimino.o ft_tetrimino_functions.o \
		ft_load_tetrimino.o check_if_valid.o check_colrow.o ft_solver.o
SRCS_DIR = srcs/
FILL_SRCS = main.c ft_array_functions.c ft_print_functions.c \
		extraction_of_tetrimino.c ft_tetrimino_functions.c \
		ft_load_tetrimino.c check_if_valid.c check_colrow.c ft_solver.c
SRCS = $(addprefix $(SRCS_DIR), $(FILL_SRCS))
LIB = make -C ./libft/

all: $(NAME)

$(NAME):
		$(LIB)
		@$(CC) $(CFLAGS) -c $(FILL_SRCS) $(INCL)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCL_LIB)


clean:
	rm -rf $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft/ fclean

re: fclean all
