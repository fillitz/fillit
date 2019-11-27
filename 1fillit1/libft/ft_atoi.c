/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:14:58 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/17 21:05:47 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	result;
	int					neg;

	neg = 1;
	result = 0;
	while ((*str == '\n') || (*str == '\t') || (*str == '\v') ||
		(*str == ' ') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str)
	{
		if (*str < 48 || 57 < *str)
			return (result * neg);
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (result > 9223372036854775807)
		return (neg == -1 ? 0 : -1);
	return (result * neg);
}
