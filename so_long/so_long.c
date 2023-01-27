/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:14:25 by sungjuki          #+#    #+#             */
/*   Updated: 2022/07/06 16:37:28 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		print_err("Map is needed or wrong arguments counts\n");
	game = malloc(sizeof(t_game));
	game_init(game, av[1]);
	mlx_hook(game->win, KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, 17, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}

void	print_err(char	*msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	game_init(t_game *g, char *map)
{
	g->mlx = mlx_init();
	g->img = img_init(g->mlx);
	map_read(map, g);
	map_check(g);
	g->win = mlx_new_window(g->mlx, g->w * 32, g->h * 32, "so_long");
	setting_img(g);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	if (key == KEY_W)
		move_w(game);
	if (key == KEY_A)
		move_a(game);
	if (key == KEY_S)
		move_s(game);
	if (key == KEY_D)
		move_d(game);
	return (0);
}
