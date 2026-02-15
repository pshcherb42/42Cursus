/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:16:33 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/21 20:16:35 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_textures(t_window *g)
{
	g->textures = ft_calloc(1, sizeof(t_txtures));
	if (!g->textures)
	{
		ft_printf("Error: Failed to allocate memory for textures\n");
		return ;
	}
	g->textures->wall = mlx_load_png("textures/wall.png");
	g->textures->floor = mlx_load_png("textures/Floor.png");
	g->textures->c1 = mlx_load_png("textures/C1.png");
	g->textures->c2 = mlx_load_png("textures/C2.png");
	g->textures->c3 = mlx_load_png("textures/C3.png");
	g->textures->p1 = mlx_load_png("textures/P1.png");
	g->textures->p2 = mlx_load_png("textures/P2.png");
	g->textures->p3 = mlx_load_png("textures/P3.png");
	g->textures->p4 = mlx_load_png("textures/P4.png");
	g->textures->e_cls = mlx_load_png("textures/E1.png");
	g->textures->e_opn = mlx_load_png("textures/E2.png");
	g->textures->enemy = mlx_load_png("textures/Enemy.png");
	g->textures->count = mlx_load_png("textures/Counter.png");
	if (!g->textures->count || !g->textures->floor
		|| !g->textures->c3 || !g->textures->p4)
		ft_printf("Failed to load textures\n");
	ft_printf("Textures loaded successfully\n");
}

void	delete_structures(t_window *g)
{
	mlx_delete_texture(g->textures->wall);
	mlx_delete_texture(g->textures->floor);
	mlx_delete_texture(g->textures->c1);
	mlx_delete_texture(g->textures->c2);
	mlx_delete_texture(g->textures->c3);
	mlx_delete_texture(g->textures->p1);
	mlx_delete_texture(g->textures->p2);
	mlx_delete_texture(g->textures->p3);
	mlx_delete_texture(g->textures->p4);
	mlx_delete_texture(g->textures->e_cls);
	mlx_delete_texture(g->textures->e_opn);
	mlx_delete_texture(g->textures->enemy);
	mlx_delete_texture(g->textures->count);
	ft_printf("Textures deleted successfully\n");
}

void	set_images(t_window *g)
{
	g->img = ft_calloc(1, sizeof(t_img));
	if (!g->img)
	{
		ft_printf("Error: Failed to allocate memory for images\n");
		return ;
	}
	g->img->wall = mlx_texture_to_image(g->mlx, g->textures->wall);
	g->img->floor = mlx_texture_to_image(g->mlx, g->textures->floor);
	g->img->c1 = mlx_texture_to_image(g->mlx, g->textures->c1);
	g->img->c2 = mlx_texture_to_image(g->mlx, g->textures->c2);
	g->img->c3 = mlx_texture_to_image(g->mlx, g->textures->c3);
	g->img->p1 = mlx_texture_to_image(g->mlx, g->textures->p1);
	g->img->p2 = mlx_texture_to_image(g->mlx, g->textures->p2);
	g->img->p3 = mlx_texture_to_image(g->mlx, g->textures->p3);
	g->img->p4 = mlx_texture_to_image(g->mlx, g->textures->p4);
	g->img->e_cls = mlx_texture_to_image(g->mlx, g->textures->e_cls);
	g->img->e_opn = mlx_texture_to_image(g->mlx, g->textures->e_opn);
	g->img->enemy = mlx_texture_to_image(g->mlx, g->textures->enemy);
	g->img->count = mlx_texture_to_image(g->mlx, g->textures->count);
	ft_printf("Images created successfully\n");
	delete_structures(g);
}

int	init_game(t_window *g)
{
	g->p.moves = 0;
	g->p.collect_counter = 0;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	g->mlx = mlx_init(g->map.width, g->map.height, "So_long", true);
	if (!g->mlx)
	{
		ft_printf("Error: Failed to initialize mlx\n");
		return (0);
	}
	ft_printf("Game initialized successfully\n");
	set_textures(g);
	set_images(g);
	ft_printf("Preparing to render\n");
	render_map(g);
	mlx_loop_hook(g->mlx, &hook_loop, g);
	mlx_key_hook(g->mlx, &moves, g);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	return (1);
}
