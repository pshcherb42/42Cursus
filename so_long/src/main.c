/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:42 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/21 20:16:44 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int			fd;
	int			len;
	t_window	mlx;

	srand(time(NULL));
	if (argc != 2)
		return (ft_printf("Usage: ./program <map_file>\n"));
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		return (ft_printf("Error: Invalid file format\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: could not open file\n"));
	ft_bzero(&mlx, sizeof(t_window));
	parsing(&mlx.map, fd, &mlx.p);
	if (!init_game(&mlx))
		return (ft_printf("Error: Failed to initialize game\n"));
	free(mlx.textures);
	free(mlx.img);
	ft_free_array(mlx.map.map);
}
