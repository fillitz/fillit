/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:32:51 by kcharlet          #+#    #+#             */
/*   Updated: 2019/09/20 16:59:21 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	start;
	int	finish;

	if (!s)
		return (NULL);
	start = 0;
	finish = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	while (s[finish] == ' ' || s[finish] == '\n' || s[finish] == '\t')
		finish--;
	return (ft_strsub((char*)s, start, finish - start + 1));
}
