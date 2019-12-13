/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:39:26 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/20 16:36:19 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*newstring;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!(newstring = (char*)malloc(sizeof(char) * ((ft_strlen(s) + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (f((((char*)s)[i])))
		{
			newstring[j] = f((((char*)s)[i]));
			j++;
		}
		i++;
	}
	newstring[j] = '\0';
	return (newstring);
}
