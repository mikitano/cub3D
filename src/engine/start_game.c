/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 00:27:52 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/01 14:38:21 by mkitano          ###   ########.fr       */
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

// void	start_game(t_game *game)
// {
// 	/*pensar na possibilidade de juntar esses, pra main não passar de 25 linhas*/
// 	mlx_loop_hook(...);
// 	mlx_key_hook(...);
// 	mlx_cursor_hook(...);
// }