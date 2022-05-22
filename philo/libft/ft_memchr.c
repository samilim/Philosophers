/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:09:15 by salimon           #+#    #+#             */
/*   Updated: 2021/01/13 16:42:46 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int ch, size_t n)
{
	unsigned int	i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)mem;
	while (i < n)
	{
		if (c[i] == (unsigned char)ch)
			return ((void *)&c[i]);
		i++;
	}
	return (NULL);
}
