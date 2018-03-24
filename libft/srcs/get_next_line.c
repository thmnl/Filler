/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:57:01 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/04 12:43:43 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

static int	end_gnl(char **str, char **line, int j, int i)
{
	char	*tmp;

	*line = ft_strndup(*str, j);
	if (i == 1)
		tmp = ft_strdup(*str + j + 1);
	else
		tmp = ft_strdup(*str + j);
	ft_bzero(*str, ft_strlen(*str));
	free(*str);
	*str = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	return (1);
}

static int	ft_check_str(char **str, char **line, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	if (!*str || !*str[0])
		return (0);
	tmp = ft_strdup(*str);
	while (tmp[j])
	{
		if (tmp[j] == '\n')
		{
			free(tmp);
			return (end_gnl(str, line, j, 1));
		}
		j++;
	}
	free(tmp);
	if (*str[0] && i == 0)
		return (end_gnl(str, line, j, 0));
	return (0);
}

static int	ft_read(int fd, char **line, char **str, char *buf)
{
	int i;
	int j;

	j = 0;
	i = 0;
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (*str == NULL)
			*str = ft_strdup(buf);
		else
			*str = ft_strjoin_free(*str, buf, 1);
		ft_bzero(buf, BUFF_SIZE + 1);
		if ((j = ft_check_str(str, line, i)) == 1)
		{
			free(buf);
			return (1);
		}
	}
	free(buf);
	if (i < 0)
		return (-1);
	return (ft_check_str(str, line, i));
}

int			get_next_line(int fd, char **line)
{
	static char	**str;
	char		*buf;

	if (!line || fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (str == NULL)
		if (!(str = (char**)malloc(sizeof(char*) * (OPEN_MAX + 2))))
			return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (ft_check_str(&str[fd], line, 1) >= 1)
	{
		free(buf);
		return (1);
	}
	return (ft_read(fd, line, &str[fd], buf));
}
