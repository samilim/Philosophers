/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:18:41 by salimon           #+#    #+#             */
/*   Updated: 2021/12/12 03:39:44 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && (cs1[i] == cs2[i]))
	{
		if ((i == n - 1) && (cs1[i] == cs2[i] && cs1[i] && cs2[i]))
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (cs1[i] - cs2[i]);
}
