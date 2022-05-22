/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:45:18 by salimon           #+#    #+#             */
/*   Updated: 2021/01/15 16:01:42 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	unsigned int	i;
	char			*c;
	char			*find_last;

	c = (char *)str;
	i = 0;
	find_last = NULL;
	while (str[i])
	{
		if (str[i] == (char)ch)
			find_last = (&c[i]);
		i++;
	}
	if (str[i] == (char)ch)
		find_last = (&c[i]);
	return (find_last);
}
