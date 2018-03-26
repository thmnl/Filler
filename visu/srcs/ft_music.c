/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_music.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:06:42 by tmanuel           #+#    #+#             */
/*   Updated: 2018/03/26 20:58:13 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillervisu.h"

int 		ft_random(void)
{
	int		fd;
	char	buf[2];
	int		random;

	fd = open("/dev/random", O_RDONLY);
	read(fd, buf, 1);
	close(fd);
	buf[1] = '\0';
	random = buf[0] % 10;
	if (random < 0)
		random *= -1;
	return (random);
}

static void	ft_music2(void)
{
	static int	rand;
	int			tmp;
	char		*tmp2;
	char		**tmp3;

	tmp = ft_random();
	while (rand == tmp)
		tmp = ft_random();
	rand = tmp;
	tmp2 = ft_strdup("visu/srcs/");
	tmp2 = ft_strjoin_free(tmp2, ft_itoa(rand), 3);
	tmp2 = ft_strjoin_free(tmp2, ".mp3", 1);
	tmp2 = ft_strjoin_free("afplay ", tmp2, 2);
	tmp3 = ft_strsplit(tmp2, ' ');
	free(tmp2);
	execve("/usr/bin/afplay", tmp3, NULL);
	free(tmp3[0]);
	free(tmp3[1]);
	exit(0);
}

void		ft_music(void)
{
	pid_t father;

	father = fork();
	if (father == 0)
		ft_music2();
}
