/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_socks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:04 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/21 20:16:09 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	collect_socks(t_window *g)
{
	int	i;
	int	count;

	i = 0;
	count = g->map.c_count;
	while (i < count)
	{
		if (g->img->c1->instances[i].y == g->img->p3->instances->y
			&& g->img->c1->instances[i].x == g->img->p3->instances->x
			&& g->img->c1->instances[i].enabled == true)
		{
			g->img->c1->instances[i].enabled = false;
			g->img->c2->instances[i].enabled = false;
			g->img->c3->instances[i].enabled = false;
			g->p.collect_counter++;
			ft_printf("Collectibles: %d\n", g->p.collect_counter);
			if (g->p.collect_counter == g->map.c_count)
			{
				g->img->e_opn->instances->enabled = true;
				ft_printf("CONGRATULATIONS!!! THE ROOM IS CLEAN NOW!\n");
			}
			return ;
		}
		i++;
	}
}
