/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:13:42 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/12 10:49:27 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	failedset(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

void	freemap(t_vars *vars)
{	
	int	x;

	x = 0;
	while (vars->map[x])
	{	
		free(vars->map[x]);
		x++;
	}
	free(vars->map[x]);
	free(vars->map);
	free(vars->mlx);
}

int	closew(int keycode, t_vars *vars, int end)
{
	int		i;

	if (keycode == RED_CROSS || keycode == KEY_ESC)
	{	
		i = 0;
		while (i < 5)
			mlx_destroy_image(vars->mlx, vars->tex[i++].img);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		freemap(vars);
		printnmouv(1, end);
		exit(0);
	}
	return (1);
}
