/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:18:43 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/23 15:18:45 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_counter(t_window *g)
{
	char	*numbers;

	numbers = ft_itoa(g->p.moves);
	mlx_image_to_window(g->mlx, g->img->count, 0, 0);
	mlx_put_string(g->mlx, numbers, 80, 20);
	free (numbers);
}

void	render_enemy(t_window *g)
{
	int	x;
	int	y;

	y = rand() % (g->map.height / 64);
	x = rand() % (g->map.width / 64);
	while (g->map.map[y][x] != 'O')
	{
		y = rand() % (g->map.height / 64);
		x = rand() % (g->map.width / 64);
	}
	mlx_image_to_window(g->mlx, g->img->enemy, x * 64, y * 64);
}
