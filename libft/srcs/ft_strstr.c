/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 06:47:36 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/10 09:01:43 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int y;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return ((char*)str);
	while (str[i])
	{
		y = 0;
		while (str[j] == to_find[y])
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
