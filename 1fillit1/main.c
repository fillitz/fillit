#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*tetrimino;
	char	**solution;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	tetrimino = ft_extract_tetrimino(argv[1]);
	solution = ft_fillit(tetrimino);
	ft_print_array(solution);
	return (0);
}