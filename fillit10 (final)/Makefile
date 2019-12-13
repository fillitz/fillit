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
OBJS = main.o ft_construction1_fillit.o ft_construction2_creation.o \
       	ft_construction3_sizing.o ft_construction4_legal.o \
       	ft_printing.o ft_validation1_extraction.o \
       	ft_validation2_checking.o \
       	ft_validation3_tetri.o
SRCS_DIR = srcs/
FILL_SRCS = main.c ft_construction1_fillit.c ft_construction2_creation.c \
		ft_construction3_sizing.c ft_construction4_legal.c \
		ft_printing.c ft_validation1_extraction.c \
		ft_validation2_checking.c \
		ft_validation3_tetri.c
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
