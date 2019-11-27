/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:16:27 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/22 21:54:22 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*in;
	unsigned char	*out;

	in = (unsigned char*)src;
	out = (unsigned char*)dst;
	i = -1;
	if ((!src && !dst) || !len)
		return (dst);
	if (in < out)
		while ((int)(--len) >= 0)
			*(out + len) = *(in + len);
	else
		while (++i < len)
			*(out + i) = *(in + i);
	return (dst);
}
