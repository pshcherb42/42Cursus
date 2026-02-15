/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:15:53 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/21 20:15:57 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_collectible_collision(t_window *g)
{
	int	player_x;
	int	player_y;

	player_x = g->img->p4->instances->x / 64;
	player_y = g->img->p4->instances->y / 64;
	if (!g->img->collectible_collected)
	{
		if (player_x == g->img->c1->instances->x / 64
			&& player_y == g->img->c1->instances->y / 64)
		{
			g->img->collectible_collected = true;
			g->img->c1->instances->enabled = false;
			g->img->c2->instances->enabled = false;
			g->img->c3->instances->enabled = false;
			g->p.collect_counter++;
		}
	}
}

void	animate_collectible(t_window *g)
{
	static double		last_time = 0;
	static int			state = 0;
	double				current_time;

	if (!g->img->collectible_collected)
	{
		current_time = mlx_get_time();
		if (current_time - last_time > 0.1)
		{
			g->img->c1->instances->enabled = false;
			g->img->c2->instances->enabled = false;
			g->img->c3->instances->enabled = false;
			if (state == 0)
				g->img->c1->instances->enabled = true;
			else if (state == 1)
				g->img->c2->instances->enabled = true;
			else if (state == 2)
				g->img->c3->instances->enabled = true;
			state = (state + 1) % 3;
			last_time = current_time;
		}
	}
}

void	hook_loop(void *param)
{
	t_window	*g;

	g = param;
	check_collectible_collision(g);
	animate_collectible(g);
}
