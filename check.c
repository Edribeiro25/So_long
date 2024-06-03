/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:42:41 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/13 12:24:31 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checknamefile(char *av)
{
	int	i;

	i = ft_strlen(av);
	while (av[i] != '.')
	{
		if (i == 0)
			failedset("Error\nBad file\n");
		i--;
	}
	if (ft_strcmp((av + i), ".ber") != 0)
		failedset("Error\nBad file extension\n");
}

void	checkmapwall(char *str, int first_last_line, int len)
{
	int	i;

	if (first_last_line == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] != '1')
			{	
				free(str);
				failedset("Error\nBad map wall\n");
			}
			i++;
		}
	}
	else
	{
		if ((str[0] != '1') || (str[len - 1] != '1'))
		{
			free(str);
			failedset("Error\nBad map wall\n");
		}
	}
}

int	checkcharmap(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P'
			&& str[i] != 'C' && str[i] != 'E')
		{
			free(str);
			failedset("Error\nBad char in map\n");
		}
		i++;
	}
	return (1);
}

int	checkplay(char *str)
{
	static int	play;
	static int	coll;
	static int	exit;
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			play++;
		if (str[i] == 'C')
			coll++;
		if (str[i] == 'E')
			exit++;
		i++;
	}
	if (exit > 0 && play == 1 && coll > 0)
		return (1);
	return (0);
}
