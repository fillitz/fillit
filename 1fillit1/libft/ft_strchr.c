/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:56:50 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/17 20:49:22 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	symbol;
	int		i;

	symbol = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == symbol)
			return (&(((char*)s)[i]));
		i++;
	}
	if (symbol == '\0')
		return (&(((char*)s)[i]));
	else
		return (NULL);
}
