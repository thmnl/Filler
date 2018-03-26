/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:08:22 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/26 20:06:38 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillervisu.h"

static void	ft_free_tab(t_libx *f)
{
	int i;

	i = 0;
	while (f->map[i])
	{
		free(f->map[i]);
		i++;
	}
	if (f->map)
		free(f->map);
}

static int	ft_score(char *s)
{
	char *line;

	line = NULL;
	ft_putendl(s);
	ft_strdel(&s);
	get_next_line(0, &line);
	ft_putendl(line);
	ft_strdel(&line);
	return (1);
}

int			ft_test(t_libx *f)
{
	char		*line;
	static int	check;

	if (check)
		return (0);
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			f = ft_malloc_mapf(line, f);
			ft_strdel(&line);
			break ;
		}
		if (ft_strstr(line, "fin"))
			return ((check = ft_score(line)));
		ft_strdel(&line);
	}
	if (!check)
	{
		ft_print(f);
		ft_free_tab(f);
	}
	return (0);
}

int			ft_key_hook(int key, t_libx *f)
{
	(void)f;
	if (key == 53)
	{
		char **tmp;

		tmp = ft_strsplit("killall afplay", ' ');
		execve("/usr/bin/killall", tmp, NULL);
	}
	return (0);
}

int			main(void)
{
	t_libx	*ptr;
	char	*line;

	if (!(ptr = (t_libx*)malloc(sizeof(t_libx))))
		return (0);
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			ptr = ft_malloc_mapf(line, ptr);
			ft_strdel(&line);
			break ;	
		}
		ft_strdel(&line);
	}
	ft_free_tab(ptr);
	ptr->scx = (10 * ptr->mapx) * 2;
	ptr->scy = 10 * ptr->mapy;
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->scx, ptr->scy, "Filler");
	ft_music();
	mlx_key_hook(ptr->win_ptr, ft_key_hook, (t_libx*)ptr);
	mlx_loop_hook(ptr->mlx_ptr, ft_test, (t_libx*)ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}
