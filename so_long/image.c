/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:39:18 by sungjuki          #+#    #+#             */
/*   Updated: 2022/06/29 15:24:29 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	rt;
	int		w;
	int		h;

	rt.land = mlx_xpm_file_to_image(mlx, "./img/land.xpm", &w, &h);
	rt.wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &w, &h);
	rt.chara = mlx_xpm_file_to_image(mlx, "./img/chara.xpm", &w, &h);
	rt.food = mlx_xpm_file_to_image(mlx, "./img/food.xpm", &w, &h);
	rt.portal = mlx_xpm_file_to_image(mlx, "./img/portal.xpm", &w, &h);
	return (rt);
}

void	put_img(t_game *g, int x, int y)
{
	if (g->str_line[y * g->w + x] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, x * 32, y * 32);
	}
	else if (g->str_line[y * g->w + x] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.food, x * 32, y * 32);
	}
	else if (g->str_line[y * g->w + x] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.chara, x * 32, y * 32);
	}
	else if (g->str_line[y * g->w + x] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.portal, x * 32, y * 32);
	}
	else if (g->str_line[y * g->w + x] == 'E' && g->all_col == g->col_cnt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.portal, x * 32, y * 32);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.land, x * 32, y * 32);
	}
}

void	setting_img(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			put_img(game, x, y);
			x++;
		}
		y++;
	}
}
