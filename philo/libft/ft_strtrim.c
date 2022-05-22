/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:45:49 by salimon           #+#    #+#             */
/*   Updated: 2021/12/12 03:38:21 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(const char *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;
	char			*res;

	if (!s1[0])
		return ((char *)s1);
	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isset(set, s1[start]))
		start++;
	while (ft_isset(set, s1[end]) && end > start)
		end--;
	res = malloc(sizeof(char) * (end - start) + 2);
	if (!res)
		return (NULL);
	while (start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
