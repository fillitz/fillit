/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:22:02 by zlucan            #+#    #+#             */
/*   Updated: 2019/11/28 17:25:04 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char *argv[])
{
	char	*tetrimino;
	char	**solution;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	tetrimino = extraction_of_tetrimino(argv[1]);
	solution = ft_fillit(tetrimino);
	ft_print_array(solution);
	free(tetrimino);
	tetrimino = NULL;
	ft_memdel((void**)solution);
	return (0);
}
