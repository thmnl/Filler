/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:40:32 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/10 11:47:03 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*fresh_s;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len] != '\0')
		len++;
	fresh_s = (char*)malloc(sizeof(char) * (len + 1));
	if (fresh_s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		fresh_s[i] = (*f)(s[i]);
		i++;
	}
	fresh_s[i] = '\0';
	return (fresh_s);
}
