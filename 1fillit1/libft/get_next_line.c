/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:02:30 by kcharlet          #+#    #+#             */
/*   Updated: 2019/10/31 13:11:13 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_d_wr_string(char **p_n, char *d_wr_string)
{
	char *str;

	if ((*p_n = ft_strchr(d_wr_string, '\n')) != NULL)
	{
		str = ft_strsub(d_wr_string, 0, *p_n - d_wr_string);
		ft_strcpy(d_wr_string, ++(*p_n));
	}
	else
	{
		str = ft_strnew(ft_strlen(d_wr_string) + 1);
		ft_strcat(str, d_wr_string);
		ft_strclr(d_wr_string);
	}
	return (str);
}

int		get_line(const int fd, char **line, char *d_wr_string)
{
	char		buf[BUFF_SIZE + 1];
	int			b_w_r;
	char		*p_n;
	char		*tmp;

	p_n = NULL;
	b_w_r = 1;
	*line = check_d_wr_string(&p_n, d_wr_string);
	while (p_n == 0 && ((b_w_r = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[b_w_r] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(d_wr_string, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || b_w_r < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return (b_w_r || ft_strlen(*line) || ft_strlen(d_wr_string)) ? 1 : 0;
}

t_list	*list_new_element(int fd)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	new->dwrstring = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (!head)
		head = list_new_element(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = list_new_element(fd);
		tmp = tmp->next;
	}
	return (get_line(fd, line, tmp->dwrstring));
}
