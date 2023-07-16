/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:15:16 by mtigunit          #+#    #+#             */
/*   Updated: 2023/02/07 07:53:37 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves(int keycode, t_long *so_long)
{
	if (keycode == ESC)
		return (ft_free(so_long->map), clear_win(so_long), \
		ft_putendl_fd("You quit the game!", 1), exit(0), 0);
	else if (keycode == W || keycode == UP)
		move_up(so_long);
	else if (keycode == S || keycode == DOWN)
		move_down(so_long);
	else if (keycode == A || keycode == LEFT)
		move_left(so_long);
	else if (keycode == D || keycode == RIGHT)
		move_right(so_long);
	return (0);
}

void	move_up(t_long *so_long)
{
	if (so_long->map[so_long->y - 1][so_long->x] != '1')
	{
		befor_move(so_long->x, so_long->y - 1, so_long);
		so_long->y -= 1;
		if (so_long->map[so_long->y][so_long->x] == 'A')
			return (ft_free(so_long->map), clear_win(so_long), \
			ft_putendl_fd("You lose!", 1), exit(0));
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_bg, so_long->x * SIZE, so_long->y * SIZE);
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_player_up, so_long->x * SIZE, so_long->y * SIZE);
		put_moves(so_long);
	}
}

void	move_down(t_long *so_long)
{
	if (so_long->map[so_long->y + 1][so_long->x] != '1')
	{		
		befor_move(so_long->x, so_long->y + 1, so_long);
		so_long->y += 1;
		if (so_long->map[so_long->y][so_long->x] == 'A')
			return (ft_free(so_long->map), clear_win(so_long), \
			ft_putendl_fd("You lose!", 1), exit(0));
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_bg, so_long->x * SIZE, so_long->y * SIZE);
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_player_down, so_long->x * SIZE, so_long->y * SIZE);
		put_moves(so_long);
	}
}

void	move_right(t_long *so_long)
{
	if (so_long->map[so_long->y][so_long->x + 1] != '1')
	{
		befor_move(so_long->x + 1, so_long->y, so_long);
		so_long->x += 1;
		if (so_long->map[so_long->y][so_long->x] == 'A')
			return (ft_free(so_long->map), clear_win(so_long), \
			ft_putendl_fd("You lose!", 1), exit(0));
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_bg, so_long->x * SIZE, so_long->y * SIZE);
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_player_right, so_long->x * SIZE, so_long->y * SIZE);
		put_moves(so_long);
	}
}

void	move_left(t_long *so_long)
{
	if (so_long->map[so_long->y][so_long->x - 1] != '1')
	{
		befor_move(so_long->x - 1, so_long->y, so_long);
		so_long->x -= 1;
		if (so_long->map[so_long->y][so_long->x] == 'A')
			return (ft_free(so_long->map), clear_win(so_long), \
			ft_putendl_fd("You lose!", 1), exit(0));
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_bg, so_long->x * SIZE, so_long->y * SIZE);
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_player_left, so_long->x * SIZE, so_long->y * SIZE);
		put_moves(so_long);
	}
}
