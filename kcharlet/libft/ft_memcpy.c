/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:52:23 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/15 19:54:20 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	i = 0;
	source = (unsigned char*)src;
	destination = (unsigned char*)dst;
	if ((!dst && !src) || !n)
		return (dst);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
