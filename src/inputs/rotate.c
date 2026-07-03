/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:42:58 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/03 12:59:38 by mkitano          ###   ########.fr       */
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

void	mouse_rotate(t_game *game)
{
	t_ivec			mouse;
	int32_t			delta_x;
	const double	mouse_sensi = 0.05;

	mlx_get_mouse_pos(game->mlx, &mouse.x, &mouse.y);
	delta_x = mouse.x - (game->mlx->width >> 1);
	if (delta_x != 0)
	{
		rotate_player(&game->player, delta_x * mouse_sensi
			* game->mlx->delta_time);
		mlx_set_mouse_pos(game->mlx,
			game->mlx->width >> 1, game->mlx->height >> 1);
	}
}

void	handle_rotate(t_game *game)
{
	game->player.rot_speed = game->mlx->delta_time * 1.4;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(&game->player, -game->player.rot_speed);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(&game->player, game->player.rot_speed);
	if (game->mouse_enable)
		mouse_rotate(game);
}

void key_hook(mlx_key_data_t key, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	if (key.key == MLX_KEY_M && key.action == MLX_PRESS)
	{
		game->mouse_enable = !game->mouse_enable;
		if (game->mouse_enable)
			mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
		else
			mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	}
	 if (key.key == MLX_KEY_N && key.action == MLX_PRESS)
		game->mini.map_on = !game->mini.map_on;
}
