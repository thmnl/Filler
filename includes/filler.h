/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 02:47:51 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/26 11:01:01 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_filler
{
	int		mapx;
	int		mapy;
	int		piecex;
	int		piecey;
	int		algocheck;
	int		piececheck;
	int		plateaucheck;
	int		validx;
	int		validy;
	int		needone;
	int		pstar;
	int		pstarmax;
	int		score;
	int		px;
	int		py;
	int		tmpx;
	int		tmpy;
	int		pax;
	int		pay;
	char	**map;
	char	**piece;
	char	**piececut;
	char	p;
}				t_filler;

int				ft_start_score(t_filler *f, int x, int y);
int				ft_calculate_score(t_filler *f, int x, int y);
t_filler		*ft_start1(t_filler *f);
t_filler		*ft_cut_piece(t_filler *f);
t_filler		*ft_start_algo(t_filler *f);
t_filler		*ft_check_map(char *s, t_filler *f);
t_filler		*ft_check_piece(char *s, t_filler *f);

#endif
