/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 02:27:47 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/24 22:47:07 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static setup_ray(t_game *game, int col)
{
	double	camera_x;

	camera_x = 2 * col / (double)game->mlx->width - 1;
	game->ray.dir.x = game->player.dir.x + game->player.plane.x * camera_x;
	game->ray.dir.y = game->player.dir.y + game->player.plane.y * camera_x;
	
	game->ray.map.x = (int)game->player.pos.x;
	game->ray.map.y = (int)game->player.pos.y;
	game->ray.delta_dis.x = fabs(1 / game->ray.dir.x);
	game->ray.delta_dis.y = fabs(1 / game->ray.dir.y);
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
