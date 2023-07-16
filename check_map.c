/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:23:15 by mtigunit          #+#    #+#             */
/*   Updated: 2023/02/08 15:57:38 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_char(t_long *so_long, char c)
{
	if (c == '0' || c == 'A')
		return ;
	else if (c == '1')
		return ;
	else if (c == 'C')
		so_long->coin_flag++;
	else if (c == 'P')
		so_long->player_flag++;
	else if (c == 'E')
		so_long->exit_flag++;
	else
		return (ft_free(so_long->map), map_error());
}

static void	check_lines(t_long *so_long, size_t len)
{
	int			i;
	int			j;

	i = 1;
	while (so_long->map[i + 1])
	{
		if (so_long->map[i][0] != '1' || so_long->map[i][len - 2] != '1'
			|| ft_strlen(so_long->map[i]) != len)
			return (ft_free(so_long->map), map_error());
		j = 0;
		while (so_long->map[i][j + 1])
		{
			if (so_long->map[i][j] == '0' || so_long->map[i][j] == '1' ||
				so_long->map[i][j] == 'C' || so_long->map[i][j] == 'P' ||
				so_long->map[i][j] == 'E' || so_long->map[i][j] == 'A')
				check_map_char(so_long, so_long->map[i][j]);
			else
				return (ft_free(so_long->map), map_error());
			j++;
		}
		if (so_long->map[i][j] != '\n')
			return (ft_free(so_long->map), map_error());
		i++;
	}
}

void	check_map(t_long *so_long, int len_2d)
{
	int	i;
	int	j;

	so_long->coin_flag = 0;
	so_long->exit_flag = 0;
	so_long->player_flag = 0;
	i = ft_strlen(so_long->map[0]) - 1;
	j = ft_strlen(so_long->map[len_2d - 1]);
	if (i != j)
		return (ft_free(so_long->map), map_error());
	while (i-- > 0)
		if (so_long->map[0][i] != '1')
			return (ft_free(so_long->map), map_error());
	while (j-- > 0)
		if (so_long->map[len_2d - 1][j] != '1')
			return (ft_free(so_long->map), map_error());
	check_lines(so_long, ft_strlen(so_long->map[0]));
	if (so_long->player_flag != 1 || so_long->exit_flag != 1
		|| so_long->coin_flag < 1)
		return (ft_free(so_long->map), map_error());
}

void	check_file(char *file)
{
	int	len;

	if (!file)
		return (ft_putendl_fd("Error: Invalid map", STDOUT_FILENO), exit(-1));
	len = ft_strlen(file);
	if (ft_memcmp(&file[len - 4], ".ber", 4))
		return (ft_putendl_fd("Error: Invalid path!", STDOUT_FILENO), exit(-1));
}
