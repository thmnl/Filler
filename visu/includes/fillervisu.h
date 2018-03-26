/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:10:28 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/26 20:10:58 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLERVISU_H
# define FILLERVISU_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define INT_MAX 2147483647
# define SCY 1080
# define SCX 1920

typedef struct	s_libx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*image;
	char	*pix;
	int		bbp;
	int		s_l;
	int		endian;
	char	**map;
	int		mapy;
	int		mapx;
	int		scx;
	int		scy;
	int		r;
}				t_libx;

void		ft_music(void);
void		ft_print(t_libx *f);
void		ft_putpixel(t_libx *env, int x, int y, int color);
t_libx		*ft_malloc_mapf(char *s, t_libx *f);
void		ft_exit_fdf(void);

#endif
