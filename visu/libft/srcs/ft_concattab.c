/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concattab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:12:33 by tmanuel           #+#    #+#             */
/*   Updated: 2018/01/14 16:07:41 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concattab(char **tab)
{
	int		i;
	char	*t;
	int		j;

	if (!tab)
		return (NULL);
	j = 0;
	i = 0;
	if (tab[1] == 0)
		return (tab[0]);
	while (tab[i])
	{
		j = ft_strlen(tab[i]) + j;
		i++;
	}
	if (!(t = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		ft_strcat(t, tab[i]);
		i++;
	}
	return (t);
}
