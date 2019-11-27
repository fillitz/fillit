#include "fillit.h"

/*
**creates a 2d char array of length and width, and initializes with '.'
**this function assumes a constant length for every column,
**so it can only be used to create squares and rectangles
*/

char			**ft_new_array(int x, int y)
{
	char	**array;
	int		i;
	int		j;

	j = 0;
	array = (char**)malloc(sizeof(char*) * (y + 1));
	while (j < y)
	{
		i = 0;
		array[j] = (char*)malloc(sizeof(char) * (x + 1));
		while (i < x)
		{
			array[j][i] = '.';
			i++;
		}
		array[j][i] = '\0';
		j++;
	}
	array[j] = NULL;
	return (array);
}

static int		ft_starting_size(char *tetrimino)
{
	int x;
	int area;
	int square;

	x = 0;
	square = 0;
	area = ((ft_strlen(tetrimino) + 1) / 21) * 4;
	while ((x++ * square++) < area)
		;
	return (x - 1);
}

t_map			*ft_starting_map(char *tetrimino)
{
	int		x;
	int		y;
	t_map	*map;

	x = ft_starting_size(tetrimino);
	y = x;
	map = (t_map*)malloc(sizeof(t_map));
	map->array = ft_new_array(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}

t_map			*ft_resize_map(t_map *old_map)
{
	int		x;
	int		y;
	t_map	*map;

	x = old_map->xmax + 1;
	y = old_map->ymax + 1;
	ft_free_map(old_map);
	map = (t_map*)malloc(sizeof(t_map));
	map->array = ft_new_array(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}