/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 21:49:25 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/30 02:04:27 by mkitano          ###   ########.fr       */
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
	game->ray.offset_y = 0;
	if (game->ray.draw_start < 0)
	{
		game->ray.offset_y = -game->ray.draw_start;
		game->ray.draw_start = 0;
	}
	game->ray.draw_end = game->mlx->height / 2 + game->ray.line_height / 2;
	if (game->ray.draw_end >= game->mlx->height)
		game->ray.draw_end = game->mlx->height - 1;
}
static mlx_texture_t *get_wall_tex(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.dir.x > 0)
			return (game->tex.ea);
		return (game->tex.we);
	}
	if (game->ray.dir.y > 0)
		return (game->tex.so);
	return (game->tex.no);
}

static void render_wall(t_game *game, mlx_texture_t *tex, int col, int y)
{
	
}

void	render_col(t_game *game, int col)
{
	int	y;

	calc_wall(game);
	y = game->ray.draw_start;
	while (y <= game->ray.draw_end)
	{
		// mlx_put_pixel(game->img, col, y, 0xFFFFFFFF);
		render_wall(game, get_wall_tex(game), col, y);
		y++;
	}
}
