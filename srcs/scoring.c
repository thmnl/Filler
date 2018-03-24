/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:05:57 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/24 16:22:33 by tmanuel          ###   ########.fr       */
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

static int	ft_check_where_is_he(t_filler *f, char *map, int i, int x)
{
	int		j;
	char	p;

	if (x > (int)ft_strlen(map))
		return (0);
	if (f->p == 'X')
		p = 'O';
	else
		p = 'X';
	j = 0;
	while (map[j + x] && j < i)
	{
		if (map[j + x] == p)
			return (1);
		j++;
	}
	j = 0;
	i = i * -1;
	while (map[j] && j > i)
	{
		if (map[j] == p)
			return (1);
		j--;
	}
	return (0);
}

static int	ft_check_distance(t_filler *f, int x, int y, int check)
{
	int i;
	int j;

	i = 1;
	while (((y - i) >= 0 || (y + i) < f->mapy) && check == 0)
	{
		j = 0;
		while (j < i)
		{
			if ((y + i) < f->mapy)
				check += ft_check_where_is_he(f, f->map[y + j], i, x);
			if ((y - i) >= 0)
				check += ft_check_where_is_he(f, f->map[y - j], i, x);
			j++;
		}
		check += ft_check_where_is_he(f, f->map[y], i, x);
		if ((y + i) < f->mapy)
			check += ft_check_where_is_he(f, f->map[y + i], i, x);
		if ((y - i) >= 0)
			check += ft_check_where_is_he(f, f->map[y - i], i, x);
		i++;
	}
	if (check)
		return (i);
	return (500);
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
	score -= ft_check_distance(f, tmpx, tmpy, 0);
	return (score);
}
