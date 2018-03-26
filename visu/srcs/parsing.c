/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:47:11 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/26 17:11:27 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillervisu.h"

static t_libx	*ft_malloc_mapf2(t_libx *f)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]))
		{
			f->map[i] = ft_strdup(line + 4);
			i++;
		}
		else
		{
			f->map[i] = 0;
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	return (f);
}

t_libx			*ft_malloc_mapf(char *s, t_libx *f)
{
	int i;

	i = 0;
	while (s[i] != ' ' && s[i])
		i++;
	if (s[i])
		i++;
	f->mapy = ft_atoi(s + i);
	while (s[i] != ' ' && s[i])
		i++;
	if (s[i])
		i++;
	f->mapx = ft_atoi(s + i);
	if (!(f->map = (char **)malloc(sizeof(char*) * (f->mapy + 1))))
		return (NULL);
	return (ft_malloc_mapf2(f));
}
