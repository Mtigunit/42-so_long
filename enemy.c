/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:00:31 by mtigunit          #+#    #+#             */
/*   Updated: 2023/02/08 11:32:46 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_player(t_long *sl)
{
	if (sl->windows)
	{
		if ((sl->x == sl->enemy_x + 1 || sl->x == sl->enemy_x - 1)
			&& sl->y == sl->enemy_y)
			return (ft_free(sl->map), clear_win(sl), \
			ft_putendl_fd("You lose!", 1), exit(0), 1);
	}
	return (0);
}

static void	move(t_long *so_long, int left, int right)
{
	if (left)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_enemy_left, (so_long->enemy_x + 1) * SIZE, \
		so_long->enemy_y * SIZE);
		mlx_put_image_to_window(so_long->mlx, so_long->windows \
		, so_long->img_bg, so_long->enemy_x * SIZE, so_long->enemy_y * SIZE);
		if (so_long->map[so_long->enemy_y][so_long->enemy_x + 1] == 'C')
			so_long->coin_flag--;
		so_long->map[so_long->enemy_y][so_long->enemy_x + 1] = 'A';
		so_long->map[so_long->enemy_y][so_long->enemy_x] = '0';
	}
	else if (right)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_enemy_right, (so_long->enemy_x - 1) * SIZE, \
		so_long->enemy_y * SIZE);
		mlx_put_image_to_window(so_long->mlx, so_long->windows \
		, so_long->img_bg, so_long->enemy_x * SIZE, so_long->enemy_y * SIZE);
		if (so_long->map[so_long->enemy_y][so_long->enemy_x - 1] == 'C')
			so_long->coin_flag--;
		so_long->map[so_long->enemy_y][so_long->enemy_x - 1] = 'A';
		so_long->map[so_long->enemy_y][so_long->enemy_x] = '0';
		so_long->enemy_x--;
	}
}

int	move_enemy(t_long *so_long)
{
	long	i;

	i = 0;
	while (i++ < 70000000)
		;
	if (so_long->dir && so_long->map[so_long->enemy_y][so_long->enemy_x + 1] \
	!= '1' && so_long->map[so_long->enemy_y][so_long->enemy_x + 1] != 'E')
	{
		move(so_long, 1, 0);
		check_player(so_long);
		so_long->enemy_x++;
	}
	else
		so_long->dir = 0;
	if (!so_long->dir && so_long->map[so_long->enemy_y][so_long->enemy_x - 1] \
	!= '1' && so_long->map[so_long->enemy_y][so_long->enemy_x - 1] != 'E')
	{
		move(so_long, 0, 1);
		check_player(so_long);
	}
	else
		so_long->dir = 1;
	return (0);
}
