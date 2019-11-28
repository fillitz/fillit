/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:22:02 by zlucan            #+#    #+#             */
/*   Updated: 2019/11/28 15:55:31 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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