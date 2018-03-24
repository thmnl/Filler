/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:14:36 by tmanuel           #+#    #+#             */
/*   Updated: 2017/11/10 08:33:49 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_char(int nb)
{
	int count;

	count = 1;
	if (nb < 0)
	{
		count = 2;
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

static void	ft_filler(char *str, int nb, int len, int neg_check)
{
	if (nb < 0)
	{
		nb = nb * -1;
		neg_check = 1;
		ft_filler(str, nb / 10, len - 1, neg_check);
	}
	else if (nb >= 10)
	{
		ft_filler(str, nb / 10, len - 1, neg_check);
	}
	if (len >= neg_check)
		str[len] = nb % 10 + 48;
}

static char	*ft_special(char *tab)
{
	tab[0] = '-';
	tab[1] = '2';
	tab[2] = '1';
	tab[3] = '4';
	tab[4] = '7';
	tab[5] = '4';
	tab[6] = '8';
	tab[7] = '3';
	tab[8] = '6';
	tab[9] = '4';
	tab[10] = '8';
	return (tab);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*tab;
	int		neg_check;

	neg_check = 0;
	len = ft_strlen_char(n);
	tab = (char*)malloc(sizeof(*tab) * (len + 1));
	if (tab == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		return (ft_special(tab));
	}
	if (n < 0)
		tab[0] = '-';
	ft_filler(tab, n, len - 1, neg_check);
	tab[len] = '\0';
	return (tab);
}
