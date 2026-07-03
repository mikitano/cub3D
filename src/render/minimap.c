/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:43:59 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/03 13:08:33 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static uint32_t	tile_color(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.cols || y >= game->map.rows)
		return (game->ceiling);
	if (game->map.grid[y][x] == '1')
		return (game->floor);
	return (0x222222FF);
}

static void	fill_tile(t_game *game, t_ivec screen, uint32_t color)
{
	uint32_t	*buffer;
	int			x;
	int			y;

	buffer = (uint32_t *)game->img->pixels;
	y = 0;
	while (y < MINI_TILE_SIZE)
	{
		x = 0;
		while (x < MINI_TILE_SIZE)
		{
			buffer[(screen.y + y) * game->img->width
				+ screen.x + x] = color;
			x++;
		}
		y++;
	}
}

static void	draw_player(t_game *game)
{
	uint32_t	*buffer;
	int			x;
	int			y;

	buffer = (uint32_t *)game->img->pixels;
	y = 0;
	while (y < PLAYER_SIZE)
	{
		x = 0;
		while (x < PLAYER_SIZE)
		{
			buffer[(game->mini.center.y + y) * game->img->width
				+ game->mini.center.x + x] = reverse_bytes(0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

static void	draw_minimap(t_game *game)
{
	int			x;
	int			y;
	t_ivec		map;
	t_ivec		screen;

	y = 0;
	while (y < MINI_DIAM)
	{
		x = 0;
		while (x < MINI_DIAM)
		{
			map.x = game->mini.start.x + x;
			map.y = game->mini.start.y + y;
			screen.x = x * MINI_TILE_SIZE;
			screen.y = y * MINI_TILE_SIZE;
			fill_tile(game, screen, 
				reverse_bytes(tile_color(game, map.x, map.y)));
			x++;
		}
		y++;
	}
}

static void	init_minimap(t_game *game)
{
	game->mini.player.x = (int)game->player.pos.x;
	game->mini.player.y = (int)game->player.pos.y;
	game->mini.start.x = game->mini.player.x - MINI_RAD;
	game->mini.start.y = game->mini.player.y - MINI_RAD;
	game->mini.center.x = MINI_RAD * MINI_TILE_SIZE;
	game->mini.center.y = MINI_RAD * MINI_TILE_SIZE;
}

void	minimap(t_game *game)
{
	if (game->mini.map_on)
	{
		init_minimap(game);
		draw_minimap(game);
		draw_player(game);
	}
}
