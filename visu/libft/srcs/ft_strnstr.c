/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 06:46:00 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/11 19:14:22 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	y;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] && i < n)
	{
		y = 0;
		while (str[j] == to_find[y] && j < n)
		{
			j++;
			y++;
			if (to_find[y] == '\0')
				return ((char*)str + i);
		}
		i++;
		j = i;
	}
	return (0);
}
