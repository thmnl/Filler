/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:48:14 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/28 14:45:24 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *str, char c)
{
	int		j;
	size_t	count;

	count = 0;
	j = 0;
	if ((str[0] != c && str[0] != '\0'))
		count++;
	while (str[j])
	{
		if (str[j] == c && str[j + 1] != c && str[j + 1] != '\0')
			count++;
		j++;
	}
	return (count);
}

static char		*ft_filler(int *j, const char *s, char c)
{
	int		k;
	int		l;
	char	*tab;

	k = 0;
	l = *j;
	tab = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		return (NULL);
	while (s[l] != c && s[l] != '\0')
	{
		tab[k] = s[l];
		k++;
		l++;
	}
	*j = l;
	tab[k] = '\0';
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	size_t	len_tab;
	int		j;

	if (!s || !c)
		return (NULL);
	j = 0;
	i = 0;
	len_tab = ft_count(s, c);
	tab = (char**)malloc(sizeof(char*) * (len_tab + 1));
	if (!tab)
		return (NULL);
	while (len_tab > 0)
	{
		while (s[j] == c && s[j] != '\0')
		{
			j++;
		}
		tab[i] = ft_filler(&j, s, c);
		len_tab--;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
