/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:40:23 by tmanuel           #+#    #+#             */
/*   Updated: 2017/09/17 19:27:36 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	ft_count(char *str)
{
	int j;
	int	count;

	count = 0;
	j = 0;
	if ((str[0] >= 33 && str[0] <= 127))
		count++;
	while (str[j])
	{
		if (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
		{
			if ((str[j + 1] >= 33 && str[j + 1] <= 127))
				count++;
		}
		j++;
	}
	return (count);
}

char	*ft_filler(int i, char **tab, char *str, int x)
{
	int j;
	int len;

	len = ft_strlen(str);
	j = 0;
	tab[i] = malloc(sizeof(char**) * (len + 1));
	while ((str[x] >= 33 && str[x] <= 127) ||
			(str[x] == '\0' && str[0] == '\0'))
	{
		tab[i][j] = str[x];
		x++;
		j++;
	}
	tab[i][j] = '\0';
	return (tab[i]);
}

int		ft_sort(int i, char **tab, char *str, int j)
{
	if (((str[0] >= 33 && str[0] <= 127)) && j == 0)
	{
		ft_filler(i, tab, str, j);
		return (j + 1);
	}
	while (str[j] != '\0')
	{
		if ((str[j] == ' ' || str[j] == '\n' || str[j] == '\t') &&
		((str[j + 1] >= 33 && str[j + 1] <= 127)))
		{
			ft_filler(i, tab, str, j + 1);
			return (j + 1);
		}
		j++;
	}
	return (j + 1);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		len_tab;
	int		j;

	j = 0;
	len_tab = ft_count(str);
	i = 0;
	tab = malloc(sizeof(char**) * (len_tab + 1));
	while (i < len_tab)
	{
		j = ft_sort(i, tab, str, j);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
