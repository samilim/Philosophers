/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llintabdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 22:28:18 by salimon           #+#    #+#             */
/*   Updated: 2022/04/08 22:29:12 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	*ft_llintabdup(long long int *tab, int size)
{
	long long int	*dest;
	int				i;

	i = 0;
	dest = malloc(sizeof(long long int) * size);
	if (!dest)
		return (0);
	while (i < size)
	{
		dest[i] = tab[i];
		i++;
	}
	return (dest);
}
