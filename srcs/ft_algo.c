/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 08:28:16 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/24 16:28:16 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_filler	*ft_check_valid2(t_filler *f, int x, int y)
{
	int	score;

	if (f->pstar == f->pstarmax && f->needone == 1)
	{
		score = ft_calculate_score(f, x, y);
		if (score >= f->score)
		{
			f->validx = x;
			f->validy = y;
			f->score = score;
		}
	}
	return (f);
}

static t_filler	*ft_check_valid(int x, int y, t_filler *f)
{
	f->pstar = 0;
	f->needone = 0;
	f->tmpy = y;
	f->py = 0;
	while (f->piececut[f->py] && f->map[y])
	{
		f->px = 0;
		f->tmpx = x;
		while (f->piececut[f->py][f->px] && f->map[y][f->tmpx])
		{
			if (f->piececut[f->py][f->px] == '*' && (f->map[y][f->tmpx] == '.'
						|| f->map[y][f->tmpx] == f->p))
			{
				f->pstar++;
				if (f->map[y][f->tmpx] == f->p)
					f->needone++;
			}
			f->px++;
			f->tmpx++;
		}
		f->py++;
		y++;
	}
	return (ft_check_valid2(f, x, f->tmpy));
}

static int		ft_calculate_star(char **piece)
{
	int x;
	int y;
	int star;

	star = 0;
	y = 0;
	while (piece[y])
	{
		x = 0;
		while (piece[y][x])
		{
			if (piece[y][x] == '*')
				star++;
			x++;
		}
		y++;
	}
	return (star);
}

t_filler		*ft_start_algo(t_filler *f)
{
	int		x;
	int		y;

	y = f->mapy - 1;
	f = ft_cut_piece(f);
	f->pstarmax = ft_calculate_star(f->piece);
	while (y >= 0)
	{
		x = f->mapx - 1;
		while (x >= 0)
		{
			f = ft_check_valid(x, y, f);
			x--;
		}
		y--;
	}
	if (f->validy != -150)
		ft_printf("%d %d\n", f->validy - (f->piecey - f->pay),
				f->validx - f->pax);
	else
		ft_printf("0 0\n", f->validy, f->validx);
	return (f);
}
