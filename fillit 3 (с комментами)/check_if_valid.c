/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:38:53 by zlucan            #+#    #+#             */
/*   Updated: 2019/11/28 15:38:53 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Increments a counter each time a # has a neighboring #.
** Total number of times we should find a neighbor is 6.
*/

/* считаем соседей */
static int			count_neighbor(char *map, int i)
{
	int				n;

	n = 0;
	if (map[i - 1] == '#')
		n++;
	if (map[i - 5] == '#')
		n++;
	if (map[i + 1] == '#')
		n++;
	if (map[i + 5] == '#')
		n++;
	return (n);
}

/*
** Checks the number of #s and if adjacency is valid
*/

/* проверяем решетки */
int					check_hash(char *str)
{
	int				hash;
	int				i;
	int				x;
	int				neighbor;

	i = 0;
	while (str[i] != '\0')
	{
		hash = 0;
		neighbor = 0;
		x = 0;
		while (x++ < 21)
		{
			if (str[i] == '#')
			{
				hash++;
				neighbor += count_neighbor(str, i);
				if (neighbor < 6 && hash == 4)
					return (1);
			}
			i++;
		}
	}
	return (0);
}

/* проверяем то, что посчитали */
static int			check_chars(t_char *count)
{
	if (count->hash < 4)
		return (1);
	if (((count->hash % 4) != 0) || ((count->dot % 4) != 0)
		|| ((count->newline + 1) % 5 != 0))
		return (1);
	else
		return (0);
}

/* считаем количество каждого знака */
static t_char		*count_chars(char *str, int i)
{
	t_char			*count;

	if(!(count = ((t_char*)malloc(sizeof(t_char)))))
		return (NULL);
	count->hash = 0;
	count->dot = 0;
	count->newline = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			count->hash++;
		if (str[i] == '.')
			count->dot++;
		if (str[i] == '\n')
			count->newline++;
		i++;
	}
	return (count);
}

/* валидация */
int					main_check(char *str)
{
	t_char			*count;
	int				i;
	int				tet;

	i = 0;
	tet = 0;
	count = count_chars(str, i);
	if (check_chars(count))
		return (1);
	tet = count->hash / 4;
	if (check_colrow(str, tet))
		return (1);
	return (0);
}