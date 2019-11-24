#include <fillit.h>

/* считаем соседей */
static int			count_neighbor(char *map, int i)
{
	int				n;

	n = 0;
	if (map[i - 1] == '#' || map[i - 5] == '#' || map[i + 1] == '#' || map[i + 5] == '#')
		n++;
	return (n);
}

/*
** Checks the number of #s and if adjacency is valid
*/

int					check_hash(char *str)
{
	int				hash;
	int				i;
	int				x;
	int				neighbor;

	i = 0;
	while (str[i])
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

/* считает символы */
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

/* считает символы */
static t_char		*count_chars(char *str, int i)
{
	t_char			*count;

	count = (t_char*)malloc(sizeof(t_char));
	count->hash = 0; /* решётки */
	count->dot = 0; /* точки */
	count->newline = 0; /* ньюлайны */
	while (str[i])
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

/* главная проверка ТУТ ОБЪЕДИНИЛ ДВЕ ФУНКЦИИ */
int					main_check(char *str)
{
	t_char			*count; /* лист */
	int				i;
	int				tet;
	int				len;

	len = ft_strlen(str);
	if (legal_char(str) || check_hash(str)) /* проверка на символы */
		return (1);
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

/* проверка адекватности символов */
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

/* присоединяем стринг, то есть присоединяем тетрамины друг к другу */
static char		addstr(void *ptr0, size_t size1)
{
	void		*ptr1; /* новый поинтер */
	size_t		size0; /* старый сайз */

	ptr1 = (char*)malloc(sizeof(char) * size1); /* задаём память под новый поинтер */
	ft_memset(ptr1, 0, size1); /* зануляем по длине size1 */
	size0 = ft_strlen(ptr0); /* size0 = strlen(ptr0)... ни добавить, ни убавить */
	ft_memcpy(ptr1, ptr0, size0); /* копируем содержимое */
	free(ptr0); /* освобождаем */
	return (ptr1); /* return */
}

/* непосредственно главная функция в извлечении каждой тетрамины */
char			*extraction(char *filename)
{
	char		*tetrimino; /* тетрамина в виде односложного массива */
	char		*tmp; /* временная тетрамина */
	int			fd; /* фэдэшниккккк */
	int			out; /* извлечение рида */
	int			max; /* макс. значение общего массива */

	/* опеним фд, задаём память фигуре и темпу, ридим фдшник */
	max = 22;
	fd = open(filename, O_RDONLY);
	figure = ft_strnew(21);
	tmp = ft_strnew(21);
	while ((out = read(fd, tmp, 21)))
	{
		ft_strcat(figure, temp); /* стркатим фигуру, присоединяя к ней темп */
		max += 21; /* увеличиваем макс на размер одной фигуры */
		figure = addstr(figure, max); /* функция присоединения стринга */
		ft_memset(tmp, 0, 21); /* заполняем временную нулями, тем самым отбрасывая её */
	}
	if (main_check(figure)) /* проверка на валидность/инвалидность */
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (figure); /* ретюрним */
}

/* на вход программа получает av[1] - название файла. Другие случаи выдают ошибку */
int		main(int ac, char **av)
{
	/* первая переменная - фигура, которая по ходу программы достаётся из данного на обработку файла
	 * вторая - результат, который получается из фигур и выводится на экран*/
	char	*figure;
	char	**result;

	/* если ac != 2 выводим ошибку. фигура получается изъятием из подаваемого файла. результат получается путем работы
	 * основного алгоритма и выводится на экран.*/
	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	figure = extraction(av[1]);
	result = ft_fillit(figure);
	ft_print_array(result);
	return (0);
}