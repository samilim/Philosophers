/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:46:08 by salimon           #+#    #+#             */
/*   Updated: 2021/12/12 03:39:00 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	taille;

	i = 0;
	d = ft_strlen(dest);
	taille = ft_strlen(src);
	if (!size)
		return (taille);
	if (size <= d)
		return (taille + size);
	else
		taille = taille + d;
	while (src[i] != '\0' && (d + 1) < size)
	{
		dest[d] = src[i];
		d++;
		i++;
	}
	dest[d] = '\0';
	return (taille);
}
