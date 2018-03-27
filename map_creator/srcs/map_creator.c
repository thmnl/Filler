/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:11:39 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/27 18:25:13 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creator.h"
#include <stdio.h>

static void	ft_create_file(t_mc *f)
{
	FILE	*fp;
	int		x;
	int		y;

	fp = fopen(f->name, "ab+");
	y = 0;
	while (y < f->ym)
	{
		x = 0;
		while (x < f->xm)
		{
			if (y == f->y1 && x == f->x1)
				fwrite("X", 1, 1, fp);
			else if (y == f->y2 && x == f->x2)
				fwrite("O", 1, 1, fp);
			else
				fwrite(".", 1, 1, fp);
			x++;
		}
		fwrite("\n", 1, 1, fp);
		y++;
	}
}

static t_mc	*ft_init(char **av, t_mc *f)
{
	int i;

	i = 0;
	f->ym = ft_atoi(av[0]);
	while (av[0][i] && av[0][i] != '.')
		i++;
	if (av[0][i])
		i++;
	f->xm = ft_atoi(av[0] + i);
	i = 0;
	f->y1 = ft_atoi(av[1]);
	while (av[1][i] && av[1][i] != '.')
		i++;
	if (av[1][i])
		i++;
	f->x1 = ft_atoi(av[1] + i);
	i = 0;
	f->y2 = ft_atoi(av[2]);
	while (av[2][i] && av[2][i] != '.')
		i++;
	if (av[2][i])
		i++;
	f->x2 = ft_atoi(av[2] + i);
	return (f);
}

int			main(int ac, char **av)
{
	t_mc *f;

	if (ac != 5)
		return (ft_printf("./map_creator Mapname Ylen.Xlen Yp1.Xp1 Yp2.Xp2\n"));
	if (!(f = (t_mc*)malloc(sizeof(t_mc))))
		return (-1);
	f->name = ft_strdup(av[1]);
	f = ft_init(av + 2, f);
	ft_create_file(f);
	return (0);
}
