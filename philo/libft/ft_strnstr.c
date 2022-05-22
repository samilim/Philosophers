/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:46:42 by salimon           #+#    #+#             */
/*   Updated: 2021/12/12 03:35:58 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	botte;
	size_t	aiguille;
	char	*cstr;
	char	*cto_find;

	cstr = (char *)str;
	cto_find = (char *)to_find;
	botte = 0;
	if (*to_find == '\0')
		return (cstr);
	while (cstr[botte] != '\0' && botte < n)
	{
		aiguille = 0;
		while (cstr[botte + aiguille] == cto_find[aiguille]
			&& (botte + aiguille) < n)
		{
			if (cto_find[aiguille + 1] == '\0')
				return (&cstr[botte]);
			aiguille++;
		}
		botte++;
	}
	return (0);
}
