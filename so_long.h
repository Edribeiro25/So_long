/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:21:16 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/12 13:49:41 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define  SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define RED_CROSS 33

typedef struct s_data {
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_data;

typedef struct s_play {
	int		x;
	int		y;
	int		col;
}				t_play;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	t_data	tex[4];
	int		xmap;
	int		x;
	int		y;
	int		mouv;
	t_play	play;
}				t_vars;

void	prt(t_vars *vars);
void	prt2(t_vars *vars);
void	prt3(t_vars *vars);
void	prt4(t_vars *vars);

char	*ft_strdup(const char *s1);

int		aff(t_vars *vars);
int		closew(int keycode, t_vars *vars, int end);
int		ft_strlen(const char *str);
int		get_next_line(int fd, char **out);
int		parsingmap(char *av, t_vars *vars);
int		ft_strcmp(const char *s1, const char *s2);
int		checkplay(char *str);
int		checkcharmap(char *str);

void	checknamefile(char *av);
void	checkmapwall(char *str, int first_last_line, int len);
void	failedset(char *str);
void	playerfind(t_vars *vars);
void	printnmouv(int end, int z);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);

#endif
