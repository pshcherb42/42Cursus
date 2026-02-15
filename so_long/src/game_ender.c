/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ender.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:25 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/21 20:16:27 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	manage_end(void)
{
	ft_printf("CONGRATULATIONS!!! THE ROOM IS CLEAN NOW!\n");
	exit(0);
}

void	game_win(t_window *g)
{
	if (g->p.collect_counter == g->map.c_count
		&& g->map.map[g->img->p4->instances->y / 64]
		[g->img->p4->instances->x / 64] == 'e')
		manage_end();
}

void	game_over(void)
{
	ft_printf("OH NO! CAZA GOT YOU!! GAME OVER!!!\n");
	exit(1);
}
