/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:56:41 by salimon           #+#    #+#             */
/*   Updated: 2021/01/13 16:40:55 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int ch, size_t n)
{
	size_t			i;
	unsigned char	*cd;
	unsigned char	*cs;

	i = 0;
	cd = (unsigned char *)dest;
	cs = (unsigned char *)src;
	while (i < n)
	{
		cd[i] = cs[i];
		if (cd[i] == (unsigned char)ch)
			return ((void *)&cd[i + 1]);
		i++;
	}
	return (NULL);
}
