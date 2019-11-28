/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:38:24 by zlucan            #+#    #+#             */
/*   Updated: 2019/11/28 15:38:24 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

/* непосредственно филлит */
char			**ft_fillit(char *tetrimino)
{
	t_tet	**pieces; /* фигуры */
	t_map	*map; /* карта */

	pieces = ft_read_all_tetrimino(tetrimino); /* тетрамины считываем */
	map = ft_starting_map(tetrimino); /*  */
	while (!ft_backtracking(pieces, map, 0)) /*  */
	{
		map = ft_resize_map(map); /*  */
	}
	return (map->array); /*  */
}