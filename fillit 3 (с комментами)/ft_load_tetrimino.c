#include "../includes/fillit.h"

static int		ft_is_legal(t_tet *t, t_map *map, int x, int y)
{
	if (x + t->x[1] < 0 || y + t->y[1] < 0)
		return (1);
	if (x + t->x[2] < 0 || y + t->y[2] < 0)
		return (1);
	if (x + t->x[3] < 0 || y + t->y[3] < 0)
		return (1);
	if (x + t->x[1] > (map->xmax - 1) || y + t->y[1] > (map->ymax - 1))
		return (1);
	if (x + t->x[2] > (map->xmax - 1) || y + t->y[2] > (map->ymax - 1))
		return (1);
	if (x + t->x[3] > (map->xmax - 1) || y + t->y[3] > (map->ymax - 1))
		return (1);
	return (0);
}

static int		ft_is_empty(t_tet *t, t_map *map, int x, int y)
{
	if (map->array[y][x] != '.')
		return (1);
	if (map->array[(y + t->y[1])][(x + t->x[1])] != '.')
		return (1);
	if (map->array[(y + t->y[2])][(x + t->x[2])] != '.')
		return (1);
	if (map->array[(y + t->y[3])][(x + t->x[3])] != '.')
		return (1);
	return (0);
}

void			ft_free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->ymax)
	{
		free(map->array[i]);
		++i;
	}
	free(map->array);
	free(map);
}

int				ft_load_tetrimino(t_tet *t, t_map *map, int x, int y)
{
	if (ft_is_legal(t, map, x, y) == 1)
		return (0);
	else if (ft_is_empty(t, map, x, y) == 1)
		return (0);
	else
	{
		map->array[y][x] = t->c;
		map->array[(y + t->y[1])][(x + t->x[1])] = t->c;
		map->array[(y + t->y[2])][(x + t->x[2])] = t->c;
		map->array[(y + t->y[3])][(x + t->x[3])] = t->c;
	}
	return (1);
}

void			ft_remove_tetrimino(t_tet *t, t_map *map, int x, int y)
{
	map->array[y][x] = '.';
	map->array[(y + t->y[1])][(x + t->x[1])] = '.';
	map->array[(y + t->y[2])][(x + t->x[2])] = '.';
	map->array[(y + t->y[3])][(x + t->x[3])] = '.';
}