/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:10:48 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/10 11:47:16 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*fresh_s;

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
		fresh_s[i] = (*f)(i, s[i]);
		i++;
	}
	fresh_s[i] = '\0';
	return (fresh_s);
}
