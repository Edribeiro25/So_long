/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:21:39 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/13 12:24:47 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkloop2(int len, int prevlen, int ret, char *line)
{
	static int	ftline;

	if (prevlen != -1 && prevlen != len)
	{
		free(line);
		failedset("Error\nBad map\n");
	}
	checkcharmap(line);
	if (ftline++ == 0 || ret == 0)
		checkmapwall(line, 1, len);
	else
	{	
		checkmapwall(line, 0, len);
	}
	return (ftline);
}

int	checkloop(int len, int ret, int fd)
{
	int		prevlen;
	char	*line;
	int		ftline;
	int		norm;

	ftline = 0;
	while (ret > 0)
	{
		prevlen = len;
		ret = get_next_line(fd, &line);
		len = ft_strlen(line);
		ftline = checkloop2(len, prevlen, ret, line);
		norm = checkplay(line);
		free(line);
	}
	if (norm == 0)
		failedset("Error\nMissing P C or E char or More than one P in map\n");
	return (ftline);
}

int	firstloop(char *av)
{
	int	len;
	int	ret;
	int	fd;
	int	i;

	len = -1;
	ret = 1;
	fd = open(av, 2);
	if (fd < 0)
		failedset("Error\nMap no exist\n");
	i = checkloop(len, ret, fd);
	close(fd);
	return (i);
}

int	parsingmap(char *av, t_vars *vars)
{
	int		i;
	int		fd;
	int		ret;
	char	*pl;
	char	**map;

	checknamefile(av);
	i = firstloop(av);
	fd = open(av, 2);
	ret = 1;
	map = ft_calloc(sizeof(char *), (i + 1));
	i = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &pl);
		map[i++] = ft_strdup(pl);
		free(pl);
	}
	vars->map = map;
	close(fd);
	return (i);
}
