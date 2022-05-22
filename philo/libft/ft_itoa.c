/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:55:31 by salimon           #+#    #+#             */
/*   Updated: 2021/12/12 03:33:34 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_create_nb(char *nb, int n, unsigned int i,
				unsigned int count)
{
	unsigned int	len;

	len = count;
	while (len > i)
	{
		nb[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	count;
	char			*nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = ft_count(n);
	nb = (char *)malloc(sizeof(char) * (count + 1));
	if (!nb)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		nb[i] = '-';
		i++;
		n = n * -1;
	}
	nb[count] = '\0';
	return (ft_create_nb(nb, n, i, count));
}
