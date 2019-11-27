/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:23:37 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/20 16:58:01 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*con;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(con = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		con[i] = ((char*)s1)[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		con[i] = ((char*)s2)[j];
		i++;
		j++;
	}
	con[i] = '\0';
	return (con);
}
