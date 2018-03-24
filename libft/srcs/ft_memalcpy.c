/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:50:49 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/12 16:57:27 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalcpy(const char *s)
{
	void	*tab;
	size_t	len;

	len = ft_strlen(s);
	tab = ft_memalloc(len);
	ft_memcpy(tab, s, len);
	return (tab);
}
