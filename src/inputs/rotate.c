/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:42:58 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/29 16:24:25 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	rotate_player(t_player *player, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	old_plane_x = player->plane.x;
	player->dir.x = player->dir.x * cos(speed) - player->dir.y * sin(speed);
	player->dir.y = old_dir_x * sin(speed) + player->dir.y * cos(speed);
	player->plane.x = player->plane.x
		* cos(speed) - player->plane.y * sin(speed);
	player->plane.y = old_plane_x * sin(speed) + player->plane.y * cos(speed);
}

void	handle_rotate(t_game *game)
{
	game->player.rot_speed = game->mlx->delta_time * 1.4;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(&game->player, -game->player.rot_speed);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(&game->player,  game->player.rot_speed);
}
