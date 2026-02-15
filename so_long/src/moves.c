/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:52 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/21 20:16:54 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_window *moves)
{
	if (moves->map.map[moves->img->p4->instances->y / 64 - 1]
		[moves->img->p4->instances->x / 64] != '1')
	{
		moves->img->p1->instances->y -= 64;
		moves->img->p2->instances->y -= 64;
		moves->img->p3->instances->y -= 64;
		moves->img->p4->instances->y -= 64;
		moves->img->p1->instances->enabled = false;
		moves->img->p2->instances->enabled = false;
		moves->img->p3->instances->enabled = false;
		moves->img->p4->instances->enabled = true;
		moves->p.moves++;
		render_counter(moves);
		ft_printf("Movimientos: %d\n", moves->p.moves);
		move_enemy(moves);
		if (moves->map.map[moves->img->p4->instances->y / 64]
			[moves->img->p4->instances->x / 64] == 'e')
			game_win(moves);
	}
}

void	move_down(t_window *moves)
{
	if (moves->map.map[moves->img->p4->instances->y / 64 + 1]
		[moves->img->p4->instances->x / 64] != '1')
	{
		moves->img->p1->instances->y += 64;
		moves->img->p2->instances->y += 64;
		moves->img->p3->instances->y += 64;
		moves->img->p4->instances->y += 64;
		moves->img->p1->instances->enabled = true;
		moves->img->p2->instances->enabled = false;
		moves->img->p3->instances->enabled = false;
		moves->img->p4->instances->enabled = false;
		moves->p.moves++;
		render_counter(moves);
		ft_printf("Movimientos: %d\n", moves->p.moves);
		move_enemy(moves);
		if (moves->map.map[moves->img->p4->instances->y / 64]
			[moves->img->p4->instances->x / 64] == 'e')
			game_win(moves);
	}
}

void	move_right(t_window *moves)
{
	if (moves->map.map[moves->img->p4->instances->y / 64]
		[moves->img->p4->instances->x / 64 + 1] != '1')
	{
		moves->img->p1->instances->x += 64;
		moves->img->p2->instances->x += 64;
		moves->img->p3->instances->x += 64;
		moves->img->p4->instances->x += 64;
		moves->img->p1->instances->enabled = false;
		moves->img->p2->instances->enabled = true;
		moves->img->p3->instances->enabled = false;
		moves->img->p4->instances->enabled = false;
		moves->p.moves++;
		render_counter(moves);
		ft_printf("Movimientos: %d\n", moves->p.moves);
		move_enemy(moves);
		if (moves->map.map[moves->img->p4->instances->y / 64]
			[moves->img->p4->instances->x / 64] == 'e')
			game_win(moves);
	}
}

void	move_left(t_window *moves)
{
	if (moves->map.map[moves->img->p4->instances->y / 64]
		[moves->img->p4->instances->x / 64 - 1] != '1')
	{
		moves->img->p1->instances->x -= 64;
		moves->img->p2->instances->x -= 64;
		moves->img->p3->instances->x -= 64;
		moves->img->p4->instances->x -= 64;
		moves->img->p1->instances->enabled = false;
		moves->img->p2->instances->enabled = false;
		moves->img->p3->instances->enabled = true;
		moves->img->p4->instances->enabled = false;
		moves->p.moves++;
		render_counter(moves);
		ft_printf("Movimientos: %d\n", moves->p.moves);
		move_enemy(moves);
		if (moves->map.map[moves->img->p4->instances->y / 64]
			[moves->img->p4->instances->x / 64] == 'e')
			game_win(moves);
	}
}

void	moves(mlx_key_data_t keydata, void *param)
{
	t_window	*moves;

	moves = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(moves);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(moves);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(moves);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(moves);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(moves->mlx);
	if (moves->map.map[moves->img->p4->instances->y / 64]
		[moves->img->p4->instances->x / 64] == 'c')
		collect_socks(moves);
	enemy_detector(moves);
}
