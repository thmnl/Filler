/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 02:47:32 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/26 12:35:50 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_filler	*ft_init(t_filler *f)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (ft_strchr(line, '1'))
		f->p = 'O';
	else
		f->p = 'X';
	f->mapx = 0;
	f->mapy = 0;
	f->piecex = 0;
	f->piecey = 0;
	f->mapx = 0;
	f->piececheck = 0;
	f->algocheck = 0;
	f->plateaucheck = 1;
	f->validx = -1;
	f->validy = -1;
	free(line);
	return (f);
}

static t_filler	*ft_algo2(t_filler *f)
{
	static int	j;
	int			i;

	i = 0;
	j++;
	if (j < f->mapy)
	{
		if (j % 2 == 0)
			f->map[f->mapy - (f->mapy / 5)][0 + (f->mapx / 5)] = 'j';
		else
			f->map[0 + (f->mapy / 5)][f->mapx - (f->mapx / 5)] = 'j';
		f = ft_start1(f);
	}
	else
		f = ft_start_algo(f);
	while (f->piececut[i])
	{
		free(f->piececut[i]);
		i++;
	}
	free(f->piececut);
	return (f);
}

static t_filler	*ft_algo(t_filler *f)
{
	int			i;

	i = 0;
	f = ft_algo2(f);
	f->plateaucheck = 1;
	f->algocheck = 0;
	while (f->map[i])
	{
		if (f->map[i])
			free(f->map[i]);
		i++;
	}
	free(f->map);
	i = 0;
	while (f->piece[i])
	{
		if (f->piece[i])
			free(f->piece[i]);
		i++;
	}
	free(f->piece);
	return (f);
}

int				main(void)
{
	t_filler	*f;
	char		*line;

	line = NULL;
	if (!(f = (t_filler*)malloc(sizeof(t_filler) * 1)))
		return (-1);
	f = ft_init(f);
	while (get_next_line(0, &line))
	{
		if (f->plateaucheck == 1)
			f = ft_check_map(line, f);
		if (f->piececheck == 1)
			f = ft_check_piece(line, f);
		if (f->algocheck == 1)
			ft_algo(f);
		ft_strdel(&line);
	}
	return (0);
}
