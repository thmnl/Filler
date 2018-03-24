/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:23:39 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/10 08:04:42 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *tab;

	tab = (void*)malloc(sizeof(size_t) * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, size);
	return ((void*)tab);
}
