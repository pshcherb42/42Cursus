/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:15 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/21 20:16:17 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	enemy_detector(t_window *g)
{
	if (g->img->p1->instances->x == g->img->enemy->instances->x
		&& g->img->p1->instances->y == g->img->enemy->instances->y)
		game_over();
}

char	sl_detect_m(t_window *g)
{
	if ((g->img->enemy->instances->x < g->img->p1->instances->x)
		&& (g->map.map[g->img->enemy->instances->y / 64]
			[g->img->enemy->instances->x / 64 + 1] != '1'))
		return ('r');
	else if ((g->img->enemy->instances->x > g->img->p1->instances->x)
		&& (g->map.map[g->img->enemy->instances->y / 64]
			[g->img->enemy->instances->x / 64 - 1] != '1'))
		return ('l');
	else if ((g->img->enemy->instances->y < g->img->p1->instances->y)
		&& (g->map.map[g->img->enemy->instances->y / 64 + 1]
			[g->img->enemy->instances->x / 64] != '1'))
		return ('d');
	else if ((g->img->enemy->instances->y > g->img->p1->instances->y)
		&& (g->map.map[g->img->enemy->instances->y / 64 - 1]
			[g->img->enemy->instances->x / 64] != '1'))
		return ('u');
	else
		return ('x');
}

void	move_enemy(t_window *g)
{
	if (sl_detect_m(g) == 'u')
		g->img->enemy->instances->y -= 64;
	else if (sl_detect_m(g) == 'd')
		g->img->enemy->instances->y += 64;
	else if (sl_detect_m(g) == 'l')
		g->img->enemy->instances->x -= 64;
	else if (sl_detect_m(g) == 'r')
		g->img->enemy->instances->x += 64;
}
