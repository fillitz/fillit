#include "../includes/fillit.h"

/* главная функция, если аргумента не 2, то выводит ошибку */
int		main(int argc, char **argv)
{
	char	*tetrimino; /* тетрамино */
	char	**solution; /* решение */

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	tetrimino = ft_extract_tetrimino(argv[1]); /* тетрамино получается в этой функции */
	solution = ft_fillit(tetrimino); /* здесь получается решение */
	ft_print_array(solution); /* вывод решения на экран */
	return (0);
}