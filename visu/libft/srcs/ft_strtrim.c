/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:44:37 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/11 19:31:26 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*tab;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (i - j <= 0)
		tab = (char*)malloc(sizeof(char) * (j - i + 2));
	else
		tab = (char*)malloc(sizeof(char) * 1);
	if (tab == NULL)
		return (NULL);
	while (i <= j)
		tab[k++] = s[i++];
	tab[k] = '\0';
	return (tab);
}
