/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:17:44 by mtigunit          #+#    #+#             */
/*   Updated: 2023/02/07 11:47:57 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	befor_move(int x, int y, t_long *so_long)
{
	if (so_long->map[so_long->y][so_long->x] == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_exit, so_long->x * SIZE, so_long->y * SIZE);
	if (so_long->map[y][x] == 'C')
	{
		so_long->map[y][x] = '0';
		so_long->coin_flag--;
	}
	if (so_long->map[y][x] == 'E' && !so_long->coin_flag)
		return (ft_free(so_long->map), clear_win(so_long), \
		ft_putendl_fd("You win!", 1), exit(0));
	if (so_long->map[so_long->y][so_long->x] != 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_bg, so_long->x * SIZE, so_long->y * SIZE);
}

void	put_moves(t_long *so_long)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(so_long->map[0]);
	while (i++ < len - 1)
		mlx_put_image_to_window(so_long->mlx, so_long->windows, \
		so_long->img_black, i * SIZE, (so_long->len_2d) * SIZE);
	so_long->moves_count++;
	so_long->move = ft_itoa(so_long->moves_count);
	mlx_string_put(so_long->mlx, so_long->windows, SIZE / 2 + 80, \
	SIZE * (so_long->len_2d + 1) - 25, 0x0000FF00, so_long->move);
	free(so_long->move);
}
