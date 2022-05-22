/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:48:06 by salimon           #+#    #+#             */
/*   Updated: 2021/01/13 17:03:08 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *mem, size_t n)
{
	size_t			i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)mem;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
	mem = c;
}
