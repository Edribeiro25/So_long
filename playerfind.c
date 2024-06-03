/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:51:13 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/13 08:16:27 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collfind(t_vars *vars)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	z = 0;
	while (vars->map[x] != 0)
	{	
		y = 0;
		while (vars->map[x][y] != '\0')
		{
			if (vars->map[x][y] == 'C')
				z++;
			y++;
		}
		x++;
	}
	vars->play.col = z;
}

void	playerfind(t_vars *vars)
{
	int		x;
	int		y;

	x = 0;
	while (vars->map[x] != 0)
	{	
		y = 0;
		while (vars->map[x][y] != '\0')
		{
			if (vars->map[x][y] == 'P')
			{	
				vars->play.x = x;
				vars->play.y = y;
				vars->map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
	collfind(vars);
}
