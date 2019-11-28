/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:02:17 by kcharlet          #+#    #+#             */
/*   Updated: 2019/11/22 18:02:22 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

int		main(int argc, char **argv)
{
	char *tetramino;
	char **solution;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		exit(1);
	}
	tetramino = extraction_of_tetramino(argv[1]);
	solution = ft_fillit(tetramino);
	ft_print_array(solution);
	return (0);
}
