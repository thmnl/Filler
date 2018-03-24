/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:04:28 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/11 15:59:19 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(t_list) * 1);
	if (tmp)
	{
		if (content)
		{
			tmp->content = (void*)malloc(content_size);
			if (!tmp->content)
			{
				free(tmp);
				return (NULL);
			}
			ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
			tmp->next = NULL;
		}
		else
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		return (tmp);
	}
	return (NULL);
}
