/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:04:50 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/23 15:04:53 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	add_map(t_map *map, char **tmp_map)
{
	int	x;
	int	y;

	map->map = ft_calloc (sizeof (char *), (map->height + 1));
	y = 0;
	while (y < map->height)
	{
		map->map[y] = ft_calloc(sizeof(char), (map->width + 1));
		if (!map->map[y])
			return (1);
		x = 0;
		while (x < map->width)
		{
			map->map[y][x] = tmp_map[y][x];
			x++;
		}
		y++;
	}
	return (0);
}

void	set_player(t_player *p, int x, int y, char **map)
{
	p->x = x;
	p->y = y;
	map[y][x] = '0';
}

void	parsing(t_map *map, int fd, t_player *p)
{
	char	**tmp_map;

	tmp_map = get_map(fd);
	if (!tmp_map)
	{
		ft_printf("Error: Failed to get map\n");
		return ;
	}
	ft_bzero(map, sizeof(t_map));
	ft_bzero(p, sizeof(t_player));
	while (tmp_map[map->height])
	{
		syntax_checker(map, tmp_map, p);
		map->height++;
	}
	if (map->c_count < 1 || map->e_count != 1 || map->p_count != 1)
		error_exit(tmp_map, "Invalid number of C, E, or P\n");
	if (sl_flood_fill(tmp_map, *p))
		error_exit(tmp_map, "Inaccessible path\n");
	if (add_map(map, tmp_map))
		error_exit(map->map, "Failed to add map\n");
	ft_free_array(tmp_map);
	map->height *= 64;
	map->width *= 64;
}
