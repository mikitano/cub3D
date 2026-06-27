/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:21:15 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/15 17:21:15 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 111111
// 100101
// 101001
// 1100N1
// 111111

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "MLX42/MLX42.h"
# include "parser.h"

# define W_WIDTH 1200
# define W_HEIGHT 800
# define TILE_SIZE 16

# define PLAYER_RADIUS 0.2

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_ivec
{
	int	x;
	int	y;
}	t_ivec;

typedef struct s_player
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	char	orientation;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
}	t_map;

typedef struct s_ray
{
	t_vec	dir;
	t_vec	side_dis;
	t_vec	delta_dis;
	t_ivec	map;
	t_ivec	step;
	int		hit_side;
}	t_ray;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			floor;
	int			ceiling;
	t_map		map;
	t_player	player;
	t_ray		ray;
}	t_game;

int		init_game(t_game *game, t_file *file);
int		init_win(t_game *game);

void	key_move(t_game *game);

void	handle_rotate(t_game *game);

#endif