#include "../includes/fillit.h"

void	ft_print_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		++i;
	}
}

void	ft_print_tetrimino(t_tet *tetrimino)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putnbr(tetrimino->x[i]);
		ft_putchar(' ');
		ft_putnbr(tetrimino->y[i]);
		ft_putchar('\n');
		++i;
	}
	ft_putchar('\n');
}