/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 00:27:52 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/01 18:18:46 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;

	key_move(game);
	handle_rotate(game);
	//draw_map(game, 0, 0, 16, 0xFFFFFFFF);
	raycast(game);
}
