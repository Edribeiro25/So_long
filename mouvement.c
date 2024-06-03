/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:36:30 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/13 08:28:37 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prt(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->play.x;
	y = vars->play.y;
	if (vars->map[x][y - 1] != '1')
	{	
		vars->play.y = y - 1;
		vars->mouv = 1;
		if (vars->map[x][y - 1] == 'E')
		{
			if (vars->play.col == 0)
			{
				aff(vars);
				closew(KEY_ESC, vars, 1);
			}
		}
		if (vars->map[x][y - 1] == 'C')
		{
			vars->play.col--;
			vars->map[x][y - 1] = '0';
		}
		printnmouv(0, 1);
	}
}

void	prt2(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->play.x;
	y = vars->play.y;
	if (vars->map[x][y + 1] != '1')
	{	
		vars->play.y = y + 1;
		vars->mouv = 1;
		if (vars->map[x][y + 1] == 'E')
		{
			if (vars->play.col == 0)
			{
				aff(vars);
				closew(KEY_ESC, vars, 1);
			}
		}
		if (vars->map[x][y + 1] == 'C')
		{
			vars->play.col--;
			vars->map[x][y + 1] = '0';
		}
		printnmouv(0, 1);
	}
}

void	prt3(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->play.x;
	y = vars->play.y;
	if (vars->map[x + 1][y] != '1')
	{	
		vars->play.x = x + 1;
		vars->mouv = 1;
		if (vars->map[x + 1][y] == 'E')
		{
			if (vars->play.col == 0)
			{
				aff(vars);
				closew(KEY_ESC, vars, 1);
			}
		}
		if (vars->map[x + 1][y] == 'C')
		{
			vars->play.col--;
			vars->map[x + 1][y] = '0';
		}
		printnmouv(0, 1);
	}
}

void	prt4(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->play.x;
	y = vars->play.y;
	if (vars->map[x - 1][y] != '1')
	{
		vars->play.x = x - 1;
		vars->mouv = 1;
		if (vars->map[x - 1][y] == 'E')
		{
			if (vars->play.col == 0)
			{
				aff(vars);
				closew(KEY_ESC, vars, 1);
			}
		}
		if (vars->map[x - 1][y] == 'C')
		{
			vars->play.col--;
			vars->map[x - 1][y] = '0';
		}
		printnmouv(0, 1);
	}	
}
