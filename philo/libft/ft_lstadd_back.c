/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:58:28 by salimon           #+#    #+#             */
/*   Updated: 2022/03/25 22:40:52 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_node **alst, t_node *new)
{
	t_node	*last;

	if (!(*alst))
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
		new->next = 0;
	}
}
