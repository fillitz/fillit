.PHONY: clean fclean re make all

FILENAMES = ft_main.c
FILENAMES += ft_array_functions.c ft_print_functions.c ft_extract_tetrimino.c
FILENAMES += ft_tetrimino_functions.c ft_load_tetrimino.c
FILENAMES += check_if_valid.c check_colrow.c ft_solver.c
NAME = fillit

SRCS	=$(addprefix srcs/, $(FILENAMES))
OBJS	=$(addprefix build/, $(FILENAMES:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I includes/
LFLAGS	= -L ./libft/ -lft

all: $(NAME)

$(NAME):$(OBJS) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS)

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./libft
	@make clean -C ./libft

clean:
	@rm -rf build/

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

build:
	@mkdir build/