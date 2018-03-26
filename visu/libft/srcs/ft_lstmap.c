/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:11:12 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/11 18:32:18 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *linked;

	fresh = (*f)(lst);
	linked = fresh;
	if (!lst || !f)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		linked->next = (*f)(lst);
		linked = linked->next;
	}
	return (fresh);
}
