/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 02:27:47 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/26 19:29:42 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void calc_side_dis(t_game *game)
{
	if (game->ray.dir.x < 0)
	{
		game->ray.step.x = -1;
		game->ray.side_dis.x =
			(game->player.pos.x - game->ray.map.x) * game->ray.delta_dis.x;
	}
	else
	{
		game->ray.step.x = 1;
		game->ray.side_dis.x = (game->ray.map.x + 1.0 - game->player.pos.x)
			* game->ray.delta_dis.x;
	}
	if (game->ray.dir.y < 0)
	{
		game->ray.step.y = -1;
		game->ray.side_dis.y =
			(game->player.pos.y - game->ray.map.y) * game->ray.delta_dis.y;
	}
	else
	{
		game->ray.step.y = 1;
		game->ray.side_dis.y = (game->ray.map.y + 1.0 - game->player.pos.y)
			* game->ray.delta_dis.y;
	}
}

static void setup_ray(t_game *game, int col)
{
	double	camera_x;

	camera_x = 2 * col / (double)game->mlx->width - 1;
	game->ray.dir.x = game->player.dir.x + game->player.plane.x * camera_x;
	game->ray.dir.y = game->player.dir.y + game->player.plane.y * camera_x;
	game->ray.map.x = (int)game->player.pos.x;
	game->ray.map.y = (int)game->player.pos.y;
	if (game->ray.dir.x == 0)
    	game->ray.delta_dis.x = 1e30;
	else
    	game->ray.delta_dis.x = fabs(1 / game->ray.dir.x);
	if (game->ray.dir.y == 0)
    	game->ray.delta_dis.y = 1e30;
	else
    	game->ray.delta_dis.y = fabs(1 / game->ray.dir.y);
	calc_side_dis(game);
}

void raycast(t_game *game)
{
	int	col;

	col = -1;
	while (++col < W_WIDTH)
	{
		setup_ray(game, col);
		/*add o resto das funções do loop p/ raycast*/
	}
}
