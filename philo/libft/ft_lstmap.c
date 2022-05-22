/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:13:31 by salimon           #+#    #+#             */
/*   Updated: 2022/03/25 22:39:46 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_node	*new_lst;
	t_node	*f_lst;

	f_lst = ft_lstnew((*f)(lst->content));
	if (!f_lst)
	{
		ft_lstclear(&lst, (*del));
		return (NULL);
	}
	new_lst = f_lst;
	lst = lst->next;
	while (lst)
	{
		f_lst = ft_lstnew((*f)(lst->content));
		if (!f_lst)
		{
			ft_lstclear(&lst, (*del));
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, f_lst);
		lst = lst->next;
	}
	return (new_lst);
}
