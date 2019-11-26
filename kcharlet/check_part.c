/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:08:29 by kcharlet          #+#    #+#             */
/*   Updated: 2019/11/24 21:08:33 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* --------------------- check for valid --------------------- */

static int	tet_one(char *str, int i)
{
	int		col;
	int		row;

	while (str[i] != '\0')
	{
		row = 1;
		while (row < 5)
		{
			col = 1;
			while (str[i] != '\n')
			{
				col++;
				i++;
			}
			if (col != 5)
				return (1);
			row++;
			i++;
		}
		if (str[i] != '\0')
			return (1);
	}
	return (0);
}

int			check_colrow(char *str, int tet)
{
	int val;

	if (tet == 1)
		val = tet_one(str, 0);
	if (tet > 1)
		val = tet_multiple(str, tet);
	if (val)
		return (1);
	else
		return (0);
}

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

static t_char		*count_chars(char *str, int i)
{
	t_char			*count;

	count = (t_char*)malloc(sizeof(t_char));
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

static int		legal_char(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (1);
		++i;
	}
	return (0);
}

static int		check_if_valid(char *str)
{
	int			len;

	len = ft_strlen(str);
	if (legal_char(str))
		return (1);
	if (main_check(str))
		return (1);
	if (check_hash(str))
		return (1);
	else
		return (0);
}
