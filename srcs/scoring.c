/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:05:57 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/26 12:26:52 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_find_star(t_filler *f, int *tmpx, int *tmpy)
{
	int x;
	int y;
	int i;

	i = 1;
	y = 0;
	while (f->piececut[y] && i)
	{
		x = 0;
		while (f->piececut[y][x] && i)
		{
			if (f->piececut[y][x] == '*')
			{
				*tmpy += y;
				*tmpx += x;
				i = 0;
			}
			x++;
		}
		y++;
	}
}

static int	ft_calculate(int my, int mx, int x, int y)
{
	int tmpy;
	int tmpx;

	if (my >= y)
		tmpy = (y - my) * -1;
	else
		tmpy = (my - y) * -1;
	if (mx >= x)
		tmpx = (x - mx) * -1;
	else
		tmpx = (mx - x) * -1;
	return (tmpx + tmpy);
}

static int	ft_check_distance(t_filler *f, int x, int y)
{
	int		mx;
	int		my;
	int		score;
	char	p;

	score = 2000;
	my = 0;
	if (f->p == 'X')
		p = 'O';
	else
		p = 'X';
	while (f->map[my])
	{
		mx = 0;
		while (f->map[my][mx])
		{
			if (f->map[my][mx] == p)
			{
				if (score > ft_calculate(my, mx, x, y))
					score = ft_calculate(my, mx, x, y);
			}
			mx++;
		}
		my++;
	}
	return (score);
}

int			ft_calculate_score(t_filler *f, int x, int y)
{
	int tmpx;
	int tmpy;
	int score;

	score = 600;
	tmpx = x;
	tmpy = y;
	ft_find_star(f, &tmpx, &tmpy);
	score -= ft_check_distance(f, tmpx, tmpy);
	return (score);
}
