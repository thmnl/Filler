/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:25:37 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/24 16:26:28 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_filler	*ft_cut_piece2(t_filler *f)
{
	int i;
	int y;
	int check;

	check = 0;
	y = 0;
	i = 0;
	if (!(f->piececut = (char**)malloc(sizeof(char*) * (f->pay + 1))))
		return (NULL);
	while (f->piece[y])
	{
		if (ft_strchr(f->piece[y], '*') || check)
		{
			check = 1;
			f->piececut[i] = ft_strdup(f->piece[y] + f->pax);
			i++;
		}
		y++;
	}
	f->piececut[i] = 0;
	return (f);
}

t_filler		*ft_cut_piece(t_filler *f)
{
	int x;
	int y;
	int check;

	check = 0;
	y = 0;
	f->pax = 2000;
	f->pay = 0;
	while (f->piece[y])
	{
		if (ft_strchr(f->piece[y], '*') || check)
		{
			check++;
			f->pay++;
		}
		x = 0;
		while (f->piece[y][x] == '.')
			x++;
		if (x < f->pax)
			f->pax = x;
		y++;
	}
	return (ft_cut_piece2(f));
}
