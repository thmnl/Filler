/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 06:41:48 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/16 08:43:23 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag			left_margingbase(t_flag lst, int i, intmax_t nb, int len)
{
	if ((((lst.type == 'o' || lst.type == 'O') && lst.flaghtag && nb != 0) ||
			((lst.type == 'o' || lst.type == 'O') && lst.flaghtag && lst.prec1
				&& !lst.prec && nb == 0)) && len >= lst.prec)
		lst.min--;
	if (((lst.flaghtag && (lst.type == 'X' || lst.type == 'x')) && nb != 0) ||
		lst.type == 'p')
		lst.min -= 2;
	if (lst.flagminus)
		return (lst);
	if (!(lst.flagzero && !lst.prec1))
		while (i < lst.min)
		{
			ft_buffer(" ", 1, 0);
			i++;
		}
	return (lst);
}

void			right_margingbase(t_flag lst, size_t len)
{
	int i;

	i = len;
	if (!lst.flagminus)
		return ;
	while (i < lst.min)
	{
		ft_buffer(" ", 1, 0);
		i++;
	}
}

void			left_signbase(t_flag lst, int len, intmax_t nb, int i)
{
	if (lst.type == 'X' && lst.flaghtag && nb)
		ft_buffer("0X", 2, 0);
	if ((lst.type == 'x' && lst.flaghtag && nb) || lst.type == 'p')
		ft_buffer("0x", 2, 0);
	if (((lst.type == 'o' || lst.type == 'O') && lst.flaghtag && nb != 0) ||
			((lst.type == 'o' || lst.type == 'O') && lst.flaghtag && lst.prec1
				&& !lst.prec && nb == 0))
	{
		len++;
		ft_buffer("0", 1, 0);
	}
	if (lst.flagzero && !lst.prec1 && !lst.flagminus)
		while (i < lst.min)
		{
			ft_buffer("0", 1, 0);
			i++;
		}
	while (len < lst.prec)
	{
		len++;
		ft_buffer("0", 1, 0);
	}
}
