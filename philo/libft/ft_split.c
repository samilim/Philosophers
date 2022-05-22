/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:34:20 by salimon           #+#    #+#             */
/*   Updated: 2021/12/18 20:48:40 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	return (NULL);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_splited_str(char const *str, char c, int lecture)
{
	int		i;
	char	*sub_str;

	i = 0;
	while (str[lecture + i] && str[lecture + i] != c)
		i++;
	sub_str = malloc(sizeof(char) * (i + 1));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (str[lecture] && str[lecture] != c)
	{
		sub_str[i] = str[lecture];
		lecture++;
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		istr;
	int		itab;

	tab = malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (!str || !tab)
		return (NULL);
	tab[ft_count_words(str, c)] = NULL;
	istr = 0;
	itab = 0;
	while (str[istr])
	{
		while (str[istr] && str[istr] == c)
			istr++;
		if (str[istr] && (itab < ft_count_words(str, c)))
		{
			tab[itab] = ft_splited_str(str, c, istr);
			if (!(tab[itab]))
				return (free_split(tab));
			itab++;
		}
		while (str[istr] && str[istr] != c)
			istr++;
	}
	return (tab);
}
