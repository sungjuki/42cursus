/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:25:04 by sungjuki          #+#    #+#             */
/*   Updated: 2022/07/06 13:30:58 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

# define KEY_PRESS		2
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img {
	void	*chara;
	void	*food;
	void	*land;
	void	*portal;
	void	*wall;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		w;
	int		h;
	char	*str_line;
	int		all_col;
	int		col_cnt;
	int		walk_cnt;
}				t_game;

char	*ft_strdup_without_nl(char *s);
int		ft_strlcpy_without_nl(char *dst, char *src, int len);
char	*ft_strjoin_without_nl(char *s1, char *s2);
t_img	img_init(void *mlx);
void	put_img(t_game *g, int w, int h);
void	setting_img(t_game *game);
void	map_read(char *filename, t_game *game);
void	map_check_wall(t_game *game);
void	map_check_params(t_game *game);
void	map_check(t_game *game);
int		clear_game(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);
void	print_err(char *message);
void	game_init(t_game *g, char *map);
int		exit_game(t_game *g);
int		press_key(int key_code, t_game *game);
int		main(int ac, char *av[]);

#endif
