/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:46:24 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/26 19:55:56 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillervisu.h"

static int	ft_pick_color(t_libx *f, int x, int y)
{
	if (f->map[y][x] == 'X')
		return (0x1b63ba);
	if (f->map[y][x] == 'x')
		return (0x247ce5);
	if (f->map[y][x] == 'O')
		return (0x9e128b);
	if (f->map[y][x] == 'o')
		return (0xc415ac);
	return (0x000000);
}

static void	ft_draw_square(t_libx *f, int x, int y)
{
	int i;
	int j;
	int color;

	color = ft_pick_color(f, x, y);
	i = 0;
	j = 0;
	x *= f->r * 2;
	y *= f->r;
	while (i < f->r - 2)
	{
		j = 0;
		while (j < (f->r * 2) - 2)
		{
			ft_putpixel(f, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

static void	ft_draw(t_libx *f)
{
	int y;
	int x;

	y = 0;
	f->r = 10;
	while (f->map[y])
	{
		x = 0;
		while (f->map[y][x])
		{
			ft_draw_square(f, x, y);
			x++;
		}
		y++;
	}
}

void		ft_print(t_libx *f)
{
	f->image = mlx_new_image(f->mlx_ptr, f->scx, f->scy);
	f->pix = mlx_get_data_addr(f->image, &f->bbp, &f->s_l, &f->endian);
	ft_draw(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->image, 0, 0);
}
