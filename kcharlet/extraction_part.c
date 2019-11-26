/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:10:45 by kcharlet          #+#    #+#             */
/*   Updated: 2019/11/24 21:10:48 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*extraction_of_tetramino(char *filename)
{
	char		*tetramino;
	char		*tmp;
	int			fd;
	int			read_ret;
	int			tetramino_size;

	tetramino_size = 21 + 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error();
	tetramino = ft_strnew(21);
	tmp = ft_strnew(21);
	while ((read_ret = read(fd, tmp, 21)))
	{
		if (read_ret == -1)
			ft_error();
		ft_strcat(tetramino, tmp);
		tetramino_size += 21;
		tetramino = add_str(tetramino, tetramino_size);
		ft_memset(tmp, 0, 21);
	}
	if (check_if_valid(tetramino))
		ft_error();
	return (tetramino);
}

void	ft_error()
{
	ft_putstr("error\n");
	exit(1);
}

static char		*add_str(void *ptr, size_t size)
{
	void		*new_ptr;
	size_t		old_size;

	new_ptr = (char*)malloc(sizeof(char) * size);
	ft_memset(new_ptr, 0, size);
	old_size = ft_strlen(ptr);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
