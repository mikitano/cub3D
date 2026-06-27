/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 02:14:38 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/27 12:26:38 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	move_up(t_player *player, t_map *map)
{
	double	new_y;

	new_y = player->pos.y - 0.1;
	if ((int)new_y < 0)
		return ;
	if (map->grid[(int)new_y][(int)player->pos.x] != '1')
		player->pos.y = new_y;
}

static void	move_down(t_player *player, t_map *map)
{
	double	new_y;
	new_y = player->pos.y + 0.1;
	if ((int)new_y > W_HEIGHT)
	return ;
	if (map->grid[(int)new_y][(int)player->pos.x] != '1')
		player->pos.y = new_y;
}
static void	move_left(t_player *player, t_map *map)
{
	double	new_x;

	new_x = player->pos.x - 0.1;
	if ((int)new_x < 0)
		return ;
	if (map->grid[(int)player->pos.y][(int)new_x] != '1')
		player->pos.x = new_x;
}

static void	move_right(t_player *player, t_map *map)
{
	double	new_x;

	new_x = player->pos.x + 0.1;
	if ((int)new_x > W_WIDTH)
		return ;
	if (map->grid[(int)player->pos.y][(int)new_x] != '1')
		player->pos.x = new_x;
}

void key_move(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(&game->player, &game->map);

	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(&game->player, &game->map);

	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(&game->player, &game->map);

	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(&game->player, &game->map);
}
