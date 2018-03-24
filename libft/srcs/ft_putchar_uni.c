/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:26:02 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/16 08:26:30 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_margin(t_flag lst)
{
	int i;

	i = 0;
	if (lst.flagzero)
		while (i < lst.min - 1)
		{
			ft_buffer("0", 1, 0);
			lst.print++;
			i++;
		}
	else
		while (i < lst.min - 1)
		{
			ft_buffer(" ", 1, 0);
			lst.print++;
			i++;
		}
	return (lst);
}

t_flag			ft_putchar_uni(wchar_t c, t_flag lst)
{
	size_t len;

	if (c)
	{
		len = ft_bit_len(c);
		while (len - 1)
		{
			lst.min--;
			len--;
		}
	}
	if (!lst.flagminus)
		lst = ft_margin(lst);
	if (c)
		ft_putchar_uni2(c);
	if (lst.flagminus)
		lst = ft_margin(lst);
	return (lst);
}
