/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:27:22 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/22 21:49:35 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;
	int		len;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (!(copy = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = ((char*)s)[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
