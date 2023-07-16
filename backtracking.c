/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:07 by mtigunit          #+#    #+#             */
/*   Updated: 2023/02/08 11:47:40 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_mapdup(t_long *so_long)
{
	int	i;

	i = -1;
	while (so_long->map[++i])
		so_long->map_cpy[i] = ft_strdup(so_long->map[i]);
}

static int	find_path(t_long *so_long, int x, int y, int coins)
{
	static int	count;

	if (so_long->map_cpy[y][x] == 'E' || so_long->map_cpy[y][x] == 'C')
		count++;
	so_long->map_cpy[y][x] = '1';
	if (so_long->map_cpy[y][x - 1] != '1')
		find_path(so_long, x - 1, y, coins);
	if (so_long->map_cpy[y][x + 1] != '1')
		find_path(so_long, x + 1, y, coins);
	if (so_long->map_cpy[y - 1][x] != '1')
		find_path(so_long, x, y - 1, coins);
	if (so_long->map_cpy[y + 1][x] != '1')
		find_path(so_long, x, y + 1, coins);
	if (count == coins + 1)
		return (1);
	return (0);
}

void	backtracking(t_long *so_long)
{
	ft_mapdup(so_long);
	if (find_path(so_long, so_long->x, so_long->y, so_long->coin_flag) == 0)
		return (ft_free(so_long->map), ft_free(so_long->map_cpy), \
		clear_win(so_long), ft_putendl_fd("Error: map has none valid path!", \
		1), exit(0));
	ft_free(so_long->map_cpy);
}
