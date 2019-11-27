/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:10:51 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/17 20:50:39 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		symbol;
	int			i;

	symbol = ((char)c);
	i = ft_strlen(s);
	if (!s)
		return (0);
	while (i > -1)
	{
		if (s[i] == symbol)
			return (&(((char*)s)[i]));
		i--;
	}
	if (symbol == '\0')
		return (&(((char*)s)[i]));
	return (0);
}
