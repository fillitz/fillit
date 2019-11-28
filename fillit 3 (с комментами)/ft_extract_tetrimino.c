/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_tetrimino.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:38:05 by zlucan            #+#    #+#             */
/*   Updated: 2019/11/28 15:38:05 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
**this assumes that the old size passed includes a null,
**that the size is char and includes the previous size,
**and that the new size is getting bigger, not smaller
*/

/* проверка адекватности знаков */
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

/* валидация */
static int		check_if_valid(char *str)
{
//	int			len;

//	len = ft_strlen(str);
	if (legal_char(str))
		return (1);
	if (main_check(str))
		return (1);
	if (check_hash(str))
		return (1);
	else
		return (0);
}

/* присоединяем стринг */
static char		*ft_append_str(void *ptr, size_t size)
{
	void		*newptr; /* новый указатель */
	size_t		old_size; /* старый размер */

	if(!(newptr = ((char*)malloc(sizeof(char) * size)))) /* задаём память новому указателю */
		return (NULL);
	ft_memset(newptr, 0, size); /* зануляем */
	old_size = ft_strlen(ptr); /* старый размер измеряем */
	ft_memcpy(newptr, ptr, old_size); /* копируем из старого в новый */
	free(ptr); /* освобождаем указатель */
	return (newptr); /* ретюрн */
}

/* извлечение тетрамино */
char			*ft_extract_tetrimino(char *filename)
{
	char		*tetrimino; /* массив содержащий совокупность тетрамин */
	char		*temp; /* временный буфер */
	int			fd; /* фдшник */
	int			ret; /* ретурн рида */
	int			size; /* число, обозначающее максимальное значение функции  */

	size = 22; /* 21 + 1 */
	fd = open(filename, O_RDONLY); /* опеним фдшник */
	tetrimino = ft_strnew(21); /* задаём память тетрамино */
	temp = ft_strnew(21); /* задаём память буферу */
	while ((ret = read(fd, temp, 21))) /* читаем */
	{
		ft_strcat(tetrimino, temp); /* присоединяем рибосому */
		size += 21; /* увеличиваем размер */
		tetrimino = ft_append_str(tetrimino, size); /* тетрамино меняется функцией */
		ft_memset(temp, 0, 21); /* зануляем */
	}
	if (check_if_valid(tetrimino)) /* валидация */
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (tetrimino);
}