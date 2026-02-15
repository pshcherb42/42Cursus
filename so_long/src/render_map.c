/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:17:19 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/21 20:17:20 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_collectible(t_window *g, int y, int x)
{
	mlx_image_to_window(g->mlx, g->img->c1, x * 64, y * 64);
	mlx_image_to_window(g->mlx, g->img->c2, x * 64, y * 64);
	mlx_image_to_window(g->mlx, g->img->c3, x * 64, y * 64);
	g->img->c2->instances->enabled = false;
	g->img->c3->instances->enabled = false;
}

void	render_exit(t_window *g, int y, int x)
{
	mlx_image_to_window(g->mlx, g->img->e_cls, x * 64, y * 64);
	mlx_image_to_window(g->mlx, g->img->e_opn, x * 64, y * 64);
	g->img->e_opn->instances->enabled = false;
}

void	render_player(t_window *g)
{
	mlx_image_to_window(g->mlx, g->img->p1, g->p.x * 64, g->p.y * 64);
	mlx_image_to_window(g->mlx, g->img->p2, g->p.x * 64, g->p.y * 64);
	mlx_image_to_window(g->mlx, g->img->p3, g->p.x * 64, g->p.y * 64);
	mlx_image_to_window(g->mlx, g->img->p4, g->p.x * 64, g->p.y * 64);
	g->img->p2->instances->enabled = false;
	g->img->p3->instances->enabled = false;
	g->img->p4->instances->enabled = false;
}

void	render_more(t_window *g)
{
	render_player(g);
	render_enemy(g);
	render_counter(g);
}

void	render_map(t_window *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.height / 64)
	{
		x = 0;
		while (x < g->map.width / 64)
		{
			if (g->map.map[y][x] == '1')
				mlx_image_to_window(g->mlx, g->img->wall, x * 64, y * 64);
			else if (g->map.map[y][x] == 'O')
				mlx_image_to_window(g->mlx, g->img->floor, x * 64, y * 64);
			else if (g->map.map[y][x] == 'c')
			{
				mlx_image_to_window(g->mlx, g->img->floor, x * 64, y * 64);
				render_collectible(g, y, x);
			}
			else if (g->map.map[y][x] == 'e')
				render_exit(g, y, x);
			x++;
		}
		y++;
	}
	render_more(g);
}
