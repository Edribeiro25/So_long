/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:45:25 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/13 12:21:19 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsingchar(t_vars *v, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(v->mlx, v->win, v-> tex[2].img, y * 32, x * 32);
	if (c == '0')
		mlx_put_image_to_window(v->mlx, v->win, v-> tex[1].img, y * 32, x * 32);
	if (c == 'C')
		mlx_put_image_to_window(v->mlx, v->win, v-> tex[3].img, y * 32, x * 32);
	if (c == 'E')
		mlx_put_image_to_window(v->mlx, v->win, v-> tex[4].img, y * 32, x * 32);
}

void	printplayer(t_vars *v, int x, int y)
{
	mlx_put_image_to_window(v->mlx, v->win, v-> tex[0].img, y * 32, x * 32);
}

int	aff(t_vars *vars)
{
	int	i;
	int	y;

	i = 0;
	if (vars->mouv > 0)
	{	
		while (vars->map[i] != 0)
		{		
			y = 0;
			while (vars->map[i][y] != '\0')
			{
				if ((i != vars->play.x) || (y != vars->play.y))
					parsingchar(vars, i, y, vars->map[i][y]);
				else
					printplayer(vars, vars->play.x, vars->play.y);
				y++;
			}
			i++;
		}
	}
	vars->mouv = 0;
	return (0);
}

void	printnmouv(int end, int mv)
{
	static int	i;

	if (i == 0)
		i = 1;
	if (end == 0)
	{
		ft_putstr_fd("Mouvement nbr : ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (end == 1 && i != 1 && mv == 1)
	{
		ft_putstr_fd("you won with ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(" mouvements \n", 1);
	}
	if (end == 1)
		ft_putstr_fd("Game quit\n", 1);
	i++;
}
