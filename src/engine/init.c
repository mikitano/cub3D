/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 02:24:31 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/18 19:34:59 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*se der errado tem ver onde dar o free ainda, talvez na main(?)*/
int	init_game(t_game *game, t_file *file)
{
	game->mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		return (1);
	}
	game->img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	if (!game->mlx || mlx_image_to_window(game->mlx, game->img, 0, 0) == -1)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		return (1);
	}
	game->floor = file->color_floor;
	game->ceiling = file->color_ceiling;
	game->map.grid = file->map;
	game->map.rows = file->total_row;
	game->map.cols = file->total_col;
	game->player.pos.x = file->player_col;
	game->player.pos.y = file->player_row;

	/* colocar as texturas no/so/we/ea depois 
		tbm falta o char player_view*/

	return (0);
}
