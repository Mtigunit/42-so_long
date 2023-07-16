/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:48:49 by mtigunit          #+#    #+#             */
/*   Updated: 2023/02/08 11:11:04 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC	53 //65307
# define A		0 //97
# define W		13 //119
# define D		2 //100
# define S		1 //115
# define UP		126 //65362
# define DOWN	125 //65364
# define LEFT	123 //65361
# define RIGHT	124 //65363
# define SIZE	50

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

typedef struct s_long {
	size_t		len_2d;
	int			width;
	int			height;
	int			x;
	int			y;
	int			moves_count;
	int			coin_flag;
	int			exit_flag;
	int			player_flag;
	char		*map_cpy[10000];
	char		*map[10000];
	char		*move;
	void		*mlx;
	void		*windows;
	void		*img_wall;
	void		*img_coin;
	void		*img_bg;
	void		*img_exit;
	void		*img_enemy_right;
	void		*img_enemy_left;
	void		*img_player_up;
	void		*img_player_down;
	void		*img_player_right;
	void		*img_player_left;
	void		*img_black;
	int			enemy_x;
	int			enemy_y;
	int			dir;
}				t_long;

//moves
int		moves(int keycode, t_long *so_long);
void	move_right(t_long *so_long);
void	move_left(t_long *so_long);
void	move_down(t_long *so_long);
void	move_up(t_long *so_long);

//map
void	open_win_draw_map(t_long *so_long, int len_2d);
void	check_map(t_long *so_long, int len_2d);
void	check_file(char *file);
void	map_error(void);
void	draw_map(t_long *so_long, int len_2d);

//utils
void	clear_win(t_long *so_long);
void	ft_free(char **strs);
int		ft_close(t_long *so_long);

//moves2
void	befor_move(int x, int y, t_long *so_long);
void	put_moves(t_long *so_long);

void	backtracking(t_long *so_long);

//enemy
int		update(t_long *so_long);
void	draw_enemy(t_long *so_long);
int		move_enemy(t_long *game);
int		move_enemy2(t_long *game);

#endif
