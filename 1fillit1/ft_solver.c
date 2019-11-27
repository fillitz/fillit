#include "fillit.h"

static int		ft_backtracking(t_tet **pieces, t_map *map, int i)
{
	int x;
	int y;

	if (pieces[i] == NULL)
		return (1);
	y = 0;
	while (y < map->ymax)
	{
		x = 0;
		while (x < map->xmax)
		{
			if (ft_load_tetrimino(pieces[i], map, x, y))
			{
				if (ft_backtracking(pieces, map, i + 1))
					return (1);
				else
					ft_remove_tetrimino(pieces[i], map, x, y);
			}
			++x;
		}
		++y;
	}
	return (0);
}

char			**ft_fillit(char *tetrimino)
{
	t_tet	**pieces;
	t_map	*map;

	pieces = ft_read_all_tetrimino(tetrimino);
	map = ft_starting_map(tetrimino);
	while (!ft_backtracking(pieces, map, 0))
	{
		map = ft_resize_map(map);
	}
	return (map->array);
}