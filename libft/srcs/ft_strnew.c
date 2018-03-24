/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:04:10 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/10 09:17:48 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = (char*)malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	while (i < size + 1)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
