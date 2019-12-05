/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction_of_tetrimino.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:48:32 by kcharlet          #+#    #+#             */
/*   Updated: 2019/11/29 16:48:41 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static	int		legal_char(char *str)
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

static	int		check_if_valid(char *str)
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

static char		*ft_append_str(void *ptr, size_t size)
{
	void		*newptr;
	size_t		old_size;

	if (!(newptr = ((char*)malloc(sizeof(char) * size))))
		return (NULL);
	ft_memset(newptr, 0, size);
	old_size = ft_strlen(ptr);
	ft_memcpy(newptr, ptr, old_size);
	free(ptr);
	ptr = NULL;
	return (newptr);
}

char			*extraction_of_tetrimino(char *filename)
{
	char		*tetrimino;
	char		*temp;
	int			fd;
	int			read_ret;
	int			tetrimino_size;

	tetrimino_size = 22;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_exit();
	tetrimino = ft_strnew(21);
	temp = ft_strnew(21);
	while ((read_ret = read(fd, temp, 21)))
	{
		if (read_ret == -1)
			ft_exit();
		ft_strcat(tetrimino, temp);
		tetrimino_size += 21;
		tetrimino = ft_append_str(tetrimino, tetrimino_size);
		ft_memset(temp, 0, 21);
	}
	ft_strdel(&temp);
	if (check_if_valid(tetrimino))
		ft_exit();
	return (tetrimino);
}

void			ft_exit(void)
{
	ft_putstr("error\n");
	exit(1);
}
