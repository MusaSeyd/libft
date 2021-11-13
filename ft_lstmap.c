/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:13:27 by fcelesti          #+#    #+#             */
/*   Updated: 2021/10/30 16:13:29 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*new;

	copy = NULL;
	while (lst && f)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&copy, del);
			return (copy);
		}
		ft_lstadd_back(&copy, new);
		lst = lst->next;
	}
	return (copy);
}
