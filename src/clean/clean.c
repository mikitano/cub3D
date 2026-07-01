/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 04:27:49 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/01 04:34:41 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	close_game(t_game *game)
{
	mlx_close_window(game->mlx);
}

void	clean_game(t_game *game, t_parser *parser)
{
	//TODO: add as funções que já temos da main para cá
	mlx_delete_image(game->mlx, game->img);
	mlx_terminate(game->mlx);
	clean_all(&parser);
}