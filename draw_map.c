/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:14:16 by mtigunit          #+#    #+#             */
/*   Updated: 2023/02/08 11:20:01 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_enemy(int y, int x, t_long *so_long)
{
	if (so_long->map[y][x] == 'A')
	{
		so_long->dir = 0;
		so_long->enemy_x = x;
		so_long->enemy_y = y;
		mlx_put_image_to_window(so_long->mlx, so_long->windows \
		, so_long->img_enemy_right, x * SIZE, y * SIZE);
		mlx_loop_hook(so_long->mlx, move_enemy, so_long);
	}
}

static void	put_img(int y, int x, t_long *so_long)
{
	if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->windows \
		, so_long->img_wall, x * SIZE, y * SIZE);
	if (so_long->map[y][x] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->windows \
		, so_long->img_coin, x * SIZE, y * SIZE);
	if (so_long->map[y][x] == '0')
		mlx_put_image_to_window(so_long->mlx, so_long->windows \
		, so_long->img_bg, x * SIZE, y * SIZE);
	if (so_long->map[y][x] == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->windows \
		, so_long->img_exit, x * SIZE, y * SIZE);
	if (so_long->map[y][x] == 'P')
	{
		so_long->x = x;
		so_long->y = y;
		mlx_put_image_to_window(so_long->mlx, so_long->windows \
		, so_long->img_player_down, x * SIZE, y * SIZE);
	}
}

void	draw_map(t_long *so_long, int len_2d)
{
	int	y;
	int	x;
	int	len;

	len = ft_strlen(so_long->map[0]);
	y = -1;
	while (++y < len_2d - 1)
	{
		x = -1;
		while (++x < len)
			mlx_put_image_to_window(so_long->mlx, so_long->windows \
			, so_long->img_bg, x * SIZE, y * SIZE);
	}
	y = -1;
	while (++y < len_2d)
	{
		x = -1;
		while (++x < len)
		{
			put_img(y, x, so_long);
			put_enemy(y, x, so_long);
		}
	}
}

static void	init_imgs(t_long *so_long)
{
	so_long->img_wall = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/wall2.xpm", &so_long->width, &so_long->height);
	so_long->img_coin = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/coin.xpm", &so_long->width, &so_long->height);
	so_long->img_bg = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/water_floor.xpm", &so_long->width, &so_long->height);
	so_long->img_black = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/black.xpm", &so_long->width, &so_long->height);
	so_long->img_exit = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/door.xpm", &so_long->width, &so_long->height);
	so_long->img_player_up = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/player_up.xpm", &so_long->width, &so_long->height);
	so_long->img_player_down = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/player_down.xpm", &so_long->width, &so_long->height);
	so_long->img_player_right = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/player_right.xpm", &so_long->width, &so_long->height);
	so_long->img_player_left = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/player_left.xpm", &so_long->width, &so_long->height);
	so_long->img_enemy_left = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/enemy_left.xpm", &so_long->width, &so_long->height);
	so_long->img_enemy_right = mlx_xpm_file_to_image(so_long->mlx \
	, "./textures/enemy_right.xpm", &so_long->width, &so_long->height);
}

void	open_win_draw_map(t_long *so_long, int len_2d)
{
	so_long->mlx = mlx_init();
	so_long->windows = mlx_new_window(so_long->mlx, \
	(ft_strlen(so_long->map[0]) - 1) * SIZE, (len_2d + 1) * SIZE, "so_long");
	init_imgs(so_long);
	draw_map(so_long, len_2d);
}
