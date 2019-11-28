/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:22:10 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/20 18:30:16 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_nbr_len(int n)
{
	size_t i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	size_t		min;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	min = 0;
	if (n < 0)
	{
		min = 1;
		n = -n;
	}
	len = min + 1 + ft_nbr_len(n);
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + 48;
		n /= 10;
	}
	if (min == 1)
		str[0] = '-';
	return (str);
}
