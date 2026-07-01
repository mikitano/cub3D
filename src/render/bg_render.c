/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 03:30:35 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/01 03:31:13 by mkitano          ###   ########.fr       */
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