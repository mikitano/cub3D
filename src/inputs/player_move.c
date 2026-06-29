/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 02:14:38 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/29 16:36:02 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	move_up(t_player *player, t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos.x + player->dir.x * player->mov_speed;
	new_y = player->pos.y + player->dir.y * player->mov_speed;
	if (map->grid[(int)player->pos.y][(int)new_x] != '1')
		player->pos.x = new_x;
	if (map->grid[(int)new_y][(int)player->pos.x] != '1')
		player->pos.y = new_y;
}

static void	move_down(t_player *player, t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos.x - player->dir.x * player->mov_speed;
	new_y = player->pos.y - player->dir.y * player->mov_speed;
	if (map->grid[(int)player->pos.y][(int)new_x] != '1')
		player->pos.x = new_x;
	if (map->grid[(int)new_y][(int)player->pos.x] != '1')
		player->pos.y = new_y;
}

static void	move_left(t_player *player, t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos.x - player->plane.x * player->mov_speed;
	new_y = player->pos.y - player->plane.y * player->mov_speed;
	if (map->grid[(int)player->pos.y][(int)new_x] != '1')
		player->pos.x = new_x;
	if (map->grid[(int)new_y][(int)player->pos.x] != '1')
		player->pos.y = new_y;
}

static void	move_right(t_player *player, t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos.x + player->plane.x * player->mov_speed;
	new_y = player->pos.y + player->plane.y * player->mov_speed;
	if (map->grid[(int)player->pos.y][(int)new_x] != '1')
		player->pos.x = new_x;
	if (map->grid[(int)new_y][(int)player->pos.x] != '1')
		player->pos.y = new_y;
}
/*ajustar a movimentação de acordo com a rotação*/
void	key_move(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		game->player.mov_speed = game->mlx->delta_time * 4.6;
	else
		game->player.mov_speed = game->mlx->delta_time * 2.2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(&game->player, &game->map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(&game->player, &game->map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(&game->player, &game->map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(&game->player, &game->map);
}
