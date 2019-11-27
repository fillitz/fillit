/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:44:07 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/17 20:52:50 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *nee)
{
	int i;
	int j;
	int k;

	i = 0;
	if (nee[i] == '\0')
		return ((char*)hay);
	while (hay[i] != '\0')
	{
		k = i;
		j = 0;
		while (nee[j] != '\0' && hay[k] != '\0' && hay[k] == nee[j])
		{
			j++;
			k++;
		}
		if (nee[j] == '\0')
			return (&(((char*)hay)[i]));
		i++;
	}
	return (NULL);
}
