/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:23:24 by mtigunit          #+#    #+#             */
/*   Updated: 2023/02/08 11:20:00 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_long	so_long;
	int		fd;

	if (ac != 2)
		return (ft_putendl_fd("Error!", 1), -1);
	check_file(av[1]);
	so_long.len_2d = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error: Invalid map", STDOUT_FILENO), -1);
	so_long.map[so_long.len_2d] = get_next_line(fd);
	if (!so_long.map[so_long.len_2d])
		return (ft_free(so_long.map), map_error(), -1);
	while (so_long.map[so_long.len_2d])
		so_long.map[++so_long.len_2d] = get_next_line(fd);
	so_long.moves_count = 0;
	check_map(&so_long, so_long.len_2d);
	open_win_draw_map(&so_long, so_long.len_2d);
	mlx_string_put(so_long.mlx, so_long.windows, SIZE / 2, \
	SIZE * (so_long.len_2d + 1) - 25, 0x0000FF00, "MOVES: ");
	backtracking(&so_long);
	mlx_hook(so_long.windows, 17, 0, ft_close, &so_long);
	mlx_hook(so_long.windows, 2, 0, moves, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
