/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:32:15 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/20 16:55:29 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2)
		return (0);
	if (!n)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i != n - 1)
		i++;
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
