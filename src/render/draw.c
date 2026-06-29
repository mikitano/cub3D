/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 21:49:25 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/29 16:03:15 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	render_bg(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	while (x < W_WIDTH)
	{
		y = 0;
		while ((int)y < (W_HEIGHT / 2))
		{
			mlx_put_pixel(game->img, x, y, game->ceiling);
			y++;
		}
		while (y < W_HEIGHT)
		{
			mlx_put_pixel(game->img, x, y, game->floor);
			y++;
		}
		x++;
	}
}

static void	calc_wall(t_game *game)
{
	game->ray.line_height = ((int)game->mlx->height / game->ray.perp_dis);
	game->ray.draw_start = game->mlx->height / 2 - game->ray.line_height / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->mlx->height / 2 + game->ray.line_height / 2;
	if (game->ray.draw_end >= game->mlx->height)
		game->ray.draw_end = game->mlx->height - 1;
}

void	render_col(t_game *game, int col)
{
	int	y;

	calc_wall(game);
	y = game->ray.draw_start;
	while (y <= game->ray.draw_end)
	{
		mlx_put_pixel(game->img, col, y, 0xFFFFFFFF);
		y++;
	}
}
