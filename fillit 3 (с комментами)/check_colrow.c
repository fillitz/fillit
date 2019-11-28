/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:39:01 by zlucan            #+#    #+#             */
/*   Updated: 2019/11/28 15:39:01 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
**Checks that the size of the cols & rows is valid
**depending on if there are one tetrimino or more than one
*/

/* одна тетрамина */
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

/* несколько тетрамин */
static int	tet_multiple(char *str, int tet)
{
	int		i;
	int		col;
	int		row;

	i = -1;
	while (tet-- != 1 && str[++i] != '\0')
	{
		row = 0;
		while (++row < 5)
		{
			col = 1;
			while (str[i] != '\n' && col++ >= 0)
				i++;
			if (col != 5)
				return (1);
			i++;
		}
		if ((row == 5) && (str[i] != '\n'))
			return (1);
	}
	if (tet == 1 && str[i] != '\0')
		tet_one(str, i);
	return (0);
}

/* интерфейс для выбора одной из двух верхних функций */
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