/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:40:01 by salimon           #+#    #+#             */
/*   Updated: 2021/01/13 17:01:30 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int ch, size_t n)
{
	size_t			i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)mem;
	while (i < n)
	{
		c[i] = (unsigned char)ch;
		i++;
	}
	return (c);
}
