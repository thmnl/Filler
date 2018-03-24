/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 07:14:03 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/21 07:45:55 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_filler	*ft_malloc_map(char *s, t_filler *f)
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
	return (f);
}

t_filler		*ft_check_map(char *s, t_filler *f)
{
	static int i;

	if (ft_strstr(s, "Plateau"))
		return ((f = ft_malloc_map(s, f)));
	if (i == f->mapy)
	{
		f->map[i] = 0;
		i = 0;
		f->piececheck = 1;
		f->plateaucheck = 0;
	}
	if (!ft_isdigit(s[0]))
		return (f);
	if (i < f->mapy)
	{
		f->map[i] = ft_strdup(s + 4);
		i++;
	}
	return (f);
}

static t_filler	*ft_malloc_piece(char *s, t_filler *f)
{
	int i;

	i = 0;
	while (s[i] != ' ' && s[i])
		i++;
	if (s[i])
		i++;
	f->piecey = ft_atoi(s + i);
	while (s[i] != ' ' && s[i])
		i++;
	if (s[i])
		i++;
	f->piecex = ft_atoi(s + i);
	if (!(f->piece = (char **)malloc(sizeof(char*) * (f->piecey + 1))))
		return (NULL);
	return (f);
}

t_filler		*ft_check_piece(char *s, t_filler *f)
{
	static int i;

	if (ft_strstr(s, "Piece"))
		return ((f = ft_malloc_piece(s, f)));
	if (i == f->piecey - 1)
	{
		f->piece[i] = ft_strdup(s);
		i++;
		f->piece[i] = 0;
		i = 0;
		f->piececheck = 0;
		f->algocheck = 1;
	}
	else if (s[0] != '.' && s[0] != '*')
		return (f);
	else if (i < f->piecey)
	{
		f->piece[i] = ft_strdup(s);
		i++;
	}
	return (f);
}
