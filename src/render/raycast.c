/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 02:27:47 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/22 02:39:22 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void setup_ray(t_game *game, int col)
{
	double	camera_x;

	camera_x = 2 * col / (double)game->mlx->width - 1;
}
