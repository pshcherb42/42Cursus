/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:17:01 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/21 20:17:03 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>
#include <stdlib.h>

char	*join_lines(char *all_in_one, char *current_line)
{
	char	*tmp_line;

	if (current_line[0] == '\n')
		error_exit(NULL, "Invalid map format\n");
	tmp_line = all_in_one;
	all_in_one = sl_strjoin(tmp_line, current_line);
	free(current_line);
	current_line = NULL;
	free(tmp_line);
	return (all_in_one);
}

char	**get_map(int fd)
{
	char	*current_line;
	char	*all_in_one;
	char	**map;

	all_in_one = NULL;
	current_line = get_next_line(fd);
	if (!current_line)
		error_exit(NULL, "Empty file or read error\n");
	while (current_line)
	{
		all_in_one = join_lines(all_in_one, current_line);
		current_line = get_next_line(fd);
	}
	map = sl_split(all_in_one, '\n');
	free(all_in_one);
	if (!map)
		error_exit(NULL, "Map split error\n");
	return (map);
}

void	syntax_checker(t_map *map, char **tmp_map, t_player *p)
{
	int	x;

	x = 0;
	while (tmp_map[map->height][x])
	{
		if (!ft_strchr("10PEC", tmp_map[map->height][x]))
			error_exit(tmp_map, "Invalid character in map\n");
		if ((!map->height || !x || !tmp_map[map->height + 1]
				|| !tmp_map[map->height][x + 1])
				&& tmp_map[map->height][x] != '1')
			error_exit(tmp_map, "Map not closed by walls\n");
		map->e_count += (tmp_map[map->height][x] == 'E');
		map->c_count += (tmp_map[map->height][x] == 'C');
		map->p_count += (tmp_map[map->height][x] == 'P');
		if (tmp_map[map->height][x] == 'P')
			set_player(p, x, map->height, tmp_map);
		x++;
	}
	if (map->height == 0)
		map->width = x;
	else if (map->width != x)
		error_exit(tmp_map, "Inconsistent row width\n");
}

void	fill_map(char **tmp_map, int y, int x, char *path)
{
	if (!ft_strchr(path, tmp_map[y][x]))
		return ;
	if (tmp_map[y][x] == '0')
		tmp_map[y][x] = 'O';
	else if (tmp_map[y][x] == 'E')
		tmp_map[y][x] = 'e';
	else if (tmp_map[y][x] == 'C')
		tmp_map[y][x] = 'c';
	fill_map(tmp_map, y + 1, x, path);
	fill_map(tmp_map, y, x + 1, path);
	fill_map(tmp_map, y - 1, x, path);
	fill_map(tmp_map, y, x - 1, path);
}

int	sl_flood_fill(char **tmp_map, t_player p)
{
	int		y;
	int		x;

	fill_map(tmp_map, p.y, p.x, "0EC");
	y = -1;
	while (tmp_map[++y])
	{
		x = -1;
		while (tmp_map[y][++x])
		{
			if (tmp_map[y][x] == 'C' || tmp_map[y][x] == 'E')
				return (1);
		}
	}
	return (0);
}
