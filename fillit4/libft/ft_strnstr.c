/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:07:43 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/17 20:53:42 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (n[i] == '\0')
		return ((char*)h);
	while (h[i] != '\0' && i < len)
	{
		k = i;
		j = 0;
		while (n[j] != '\0' && h[k] != '\0' && h[k] == n[j] && k < len)
		{
			j++;
			k++;
		}
		if (n[j] == '\0')
			return (&(((char*)h)[i]));
		i++;
	}
	return (NULL);
}
