/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:15:10 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/21 20:15:16 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		c_count;
	int		e_count;
	int		p_count;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
	int	collect_counter;
}	t_player;

typedef struct s_txtures
{
	mlx_texture_t	*e_cls;
	mlx_texture_t	*e_opn;
	mlx_texture_t	*c1;
	mlx_texture_t	*c2;
	mlx_texture_t	*c3;
	mlx_texture_t	*p1;
	mlx_texture_t	*p2;
	mlx_texture_t	*p3;
	mlx_texture_t	*p4;
	mlx_texture_t	*enemy;
	mlx_texture_t	*count;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
}	t_txtures;

typedef struct s_img
{
	mlx_image_t	*e_cls;
	mlx_image_t	*e_opn;
	mlx_image_t	*c1;
	mlx_image_t	*c2;
	mlx_image_t	*c3;
	mlx_image_t	*p1;
	mlx_image_t	*p2;
	mlx_image_t	*p3;
	mlx_image_t	*p4;
	mlx_image_t	*enemy;
	mlx_image_t	*count;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	bool		collectible_collected;
}	t_img;

typedef struct s_window
{
	mlx_t		*mlx;
	t_player	p;
	t_map		map;
	t_txtures	*textures;
	t_img		*img;
}	t_window;

void	render_map(t_window *g);
void	render_more(t_window *g);
void	render_exit(t_window *g, int y, int x);
void	render_collectible(t_window *g, int y, int x);
void	render_player(t_window *g);
void	render_enemy(t_window *g);
void	render_counter(t_window *g);
void	moves(mlx_key_data_t keydata, void *param);
void	move_down(t_window *moves);
void	move_up(t_window *moves);
void	move_right(t_window *moves);
void	move_left(t_window *moves);
void	move_enemy(t_window *g);
void	hook_loop(void *param);
void	animate_collectible(t_window *g);
void	enemy_detector(t_window *g);
void	game_over(void);
void	collect_socks(t_window *g);
void	game_win(t_window *g);
char	sl_detect_m(t_window *g);
int		ft_array_count(char **ptr);
int		add_map(t_map *map, char **tmp_map);
int		init_game(t_window *g);
void	set_images(t_window *g);
void	delete_structures(t_window *g);
void	set_textures(t_window *g);
char	**sl_split(char const *s, char c);
char	*sl_strjoin(char const *s1, char const *s2);
void	ft_free_array(char **array);
void	set_player(t_player *p, int x, int y, char **map);
void	error_exit(char **map, const char *msg);
char	**get_map(int fd);
void	syntax_checker(t_map *map, char **tmp_map, t_player *p);
void	fill_map(char **tmp_map, int y, int x, char *path);
int		sl_flood_fill(char **tmp_map, t_player p);
void	parsing(t_map *map, int fd, t_player *p);
void	check_collectible_collision(t_window *g);
void	manage_end(void);

#endif
