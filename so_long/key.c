/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:15:28 by sungjuki          #+#    #+#             */
/*   Updated: 2022/07/06 14:58:44 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clear_game(t_game *game)
{
	game->walk_cnt++;
	printf("%s %s : %d\n", "so long!", "steps", game->walk_cnt);
	exit(0);
}

void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (i < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
		i++;
	}
	if (g->str_line[i - g->w] == 'C')
		g->col_cnt++;
	if (g->str_line[i - g->w] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i - g->w] != '1' && g->str_line[i - g->w] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->w] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (i < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
		i++;
	}
	if (g->str_line[i - 1] == 'C')
		g->col_cnt++;
	if (g->str_line[i - 1] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (i < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
		i++;
	}
	if (g->str_line[i + g->w] == 'C')
		g->col_cnt++;
	if (g->str_line[i + g->w] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i + g->w] != '1' && g->str_line[i + g->w] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + g->w] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (i < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
		i++;
	}
	if (g->str_line[i + 1] == 'C')
		g->col_cnt++;
	if (g->str_line[i + 1] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}
