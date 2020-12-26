/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:18:09 by gkim              #+#    #+#             */
/*   Updated: 2020/12/26 18:11:32 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;

	if (f == NULL)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		if (ft_lstnew(f(lst->content)) == NULL)
		{
			ft_lstclear(&newlist, del);
			break ;
		}
		ft_lstadd_back(&newlist, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (newlist);
}
