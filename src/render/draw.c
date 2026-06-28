/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 21:49:25 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/28 22:10:01 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void cal_wall(t_game *game)
{
	game->ray.line_height = ((int)game->mlx->height / game->ray.perp_dis);
	game->ray.draw_start = game->mlx->height / 2 - game->ray.line_height / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->mlx->height / 2 + game->ray.line_height / 2;
	if (game->ray.draw_end >= game->mlx->height)
		game->ray.draw_end = game->mlx->height - 1;
}
