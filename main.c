/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:48:18 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/12 11:01:40 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_A)
		prt(vars);
	if (keycode == KEY_D)
		prt2(vars);
	if (keycode == KEY_S)
		prt3(vars);
	if (keycode == KEY_W)
		prt4(vars);
	if (keycode == KEY_ESC)
		closew(keycode, vars, 0);
	return (1);
}

void	set_tex(char *path, t_vars *vars, t_data *tex)
{
	tex->img = mlx_xpm_file_to_image(vars->mlx, path, &tex->img_width,
			&tex->img_height);
}

void	tex_all(t_vars *vars)
{
	set_tex("./textures/perso.xpm", vars, &vars->tex[0]);
	set_tex("./textures/floor.xpm", vars, &vars->tex[1]);
	set_tex("./textures/wall.xpm", vars, &vars->tex[2]);
	set_tex("./textures/coll.xpm", vars, &vars->tex[3]);
	set_tex("./textures/exit.xpm", vars, &vars->tex[4]);
}

int	event_quit(t_vars *vars)
{
	closew(RED_CROSS, vars, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		i;
	int		z;

	if (ac != 2)
		failedset("Error\n");
	vars.x = 0;
	vars.y = 0;
	vars.mouv = 1;
	i = parsingmap(av[1], &vars);
	z = ft_strlen(vars.map[0]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, z * 32, i * 32, "So_long");
	tex_all(&vars);
	playerfind(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, RED_CROSS, 1L << 2, event_quit, &vars);
	mlx_loop_hook(vars.mlx, aff, &vars);
	mlx_loop(vars.mlx);
}
