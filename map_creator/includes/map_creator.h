/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:13:24 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/27 17:53:14 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CREATOR_H
# define MAP_CREATOR_H

# include "libft.h"

typedef struct	s_mc
{
	char	*name;
	int		ym;
	int		xm;
	int		y1;
	int		x1;
	int		y2;
	int		x2;
}				t_mc;

#endif
