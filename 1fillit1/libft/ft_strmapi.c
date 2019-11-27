/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:08:29 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/16 20:18:36 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*newstring;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!(newstring = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		newstring[j] = f(i, (((char*)s)[i]));
		j++;
		i++;
	}
	newstring[j] = '\0';
	return (newstring);
}
