/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:47:00 by mtigunit          #+#    #+#             */
/*   Updated: 2023/02/08 11:04:03 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_error(void)
// {
// 	ft_putendl_fd("Error!", STDOUT_FILENO);
// 	exit(-1);
// }

void	clear_win(t_long *so_long)
{
	mlx_destroy_image(so_long->mlx, so_long->img_bg);
	mlx_destroy_image(so_long->mlx, so_long->img_coin);
	mlx_destroy_image(so_long->mlx, so_long->img_exit);
	mlx_destroy_image(so_long->mlx, so_long->img_player_left);
	mlx_destroy_image(so_long->mlx, so_long->img_player_down);
	mlx_destroy_image(so_long->mlx, so_long->img_player_right);
	mlx_destroy_image(so_long->mlx, so_long->img_player_up);
	mlx_destroy_image(so_long->mlx, so_long->img_wall);
	mlx_destroy_image(so_long->mlx, so_long->img_enemy_left);
	mlx_destroy_image(so_long->mlx, so_long->img_enemy_right);
	mlx_destroy_image(so_long->mlx, so_long->img_black);
	if (so_long->windows)
	{
		mlx_clear_window(so_long->mlx, so_long->windows);
		mlx_destroy_window(so_long->mlx, so_long->windows);
	}
}

void	map_error(void)
{
	ft_putendl_fd("Error: Invalid map!", STDOUT_FILENO);
	exit(-1);
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
}

int	ft_close(t_long *so_long)
{
	ft_free(so_long->map);
	clear_win(so_long);
	exit(0);
	return (0);
}
