/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaiache <aaiache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:40:48 by aaiache           #+#    #+#             */
/*   Updated: 2025/08/27 16:40:41 by aaiache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lent;
	char	*res;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (start + len > ft_strlen(s))
		lent = ft_strlen(s) - start;
	else
		lent = len;
	res = malloc(sizeof(char) * (lent + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (lent > 0 && s[start])
	{
		res[i] = s[start];
		i++;
		start++;
		lent--;
	}
	res[i] = '\0';
	return (res);
}
