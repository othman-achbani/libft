/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:35:54 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/06 17:51:13 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*p;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	p = NULL;
	current = lst;
	while (current)
	{
		new = ft_lstnew((*f)(current -> content));
		if (!new)
		{
			ft_lstclear(&p, (*del));
			return (NULL);
		}
		ft_lstadd_back(&p, new);
		current = current->next;
	}
	return (p);
}
