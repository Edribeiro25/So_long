/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:01:59 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/08 15:07:41 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*recurs_if(char *out, int depth, int *ret, char *buff)
{
	if (!out)
		return (0);
	out[depth] = 0;
	*ret = 1;
	if (buff[0] == 0)
		*ret = 0;
	return (out);
}

char	*recurs(int depth, int *ret, int fd)
{
	char	buff[1];
	char	*out;
	int		test;

	test = read(fd, buff, 1);
	if (test == 0)
		buff[0] = 0;
	if (buff[0] == '\n' || buff[0] == 0)
	{
		out = malloc(sizeof(char) * depth + 1);
		return (recurs_if(out, depth, ret, buff));
	}
	else
	{
		out = recurs(depth + 1, ret, fd);
		if (!out)
			return (0);
		out[depth] = buff[0];
	}
	return (out);
}

int	get_next_line(int fd, char **out)
{
	int		ret;

	ret = 1;
	*out = recurs(0, &ret, fd);
	return (ret);
}
