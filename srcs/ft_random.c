/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:33:32 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/26 11:36:24 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_filler	*ft_check_valid2(t_filler *f, int x, int y)
{
	int	score;
	if (f->pstar == f->pstarmax && f->needone == 1)
	{
		FILE *fp = fopen("toto.txt", "a+");
		score = ft_start_score(f, x, y);
		fprintf(fp, "%d %d\n", score, f->score);
		if (score >= f->score)
		{
			f->validx = x;
			f->validy = y;
			f->score = score;
		}
		fclose(fp);
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

t_filler		*ft_start1(t_filler *f)
{
	int		x;
	int		y;

	f->validy = -150;
	f->validx = -150;
	y = f->mapy - 1;
	f = ft_cut_piece(f);
	f->score = 0;
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
	if (f->validx != -150)
		ft_printf("%d %d\n", f->validy - (f->piecey - f->pay),
				f->validx - f->pax);
	else
		ft_printf("0 0\n", f->validy, f->validx);
	return (f);
}
