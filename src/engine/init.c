/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 02:24:31 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/27 16:22:26 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	set_player_dir(t_game *game)
{
	if (game->player.orientation == 'N')
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
	}	
	else if (game->player.orientation == 'S')
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
	}
	else if (game->player.orientation == 'E')
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
	}
	else if (game->player.orientation == 'W')
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
	}
	/*plane é perpendicuar a dri, então sempre vai parecer um T*/
	game->player.plane.x = -game->player.dir.y * 0.66;
	game->player.plane.y = game->player.dir.x * 0.66;
}

/*se der errado tem ver onde dar o free ainda, talvez na main(?)*/
int	init_game(t_game *game, t_file *file)
{
	game->floor = file->color_floor;
	game->ceiling = file->color_ceiling;
	game->map.grid = file->map;
	game->map.rows = file->total_row;
	game->map.cols = file->total_col;
	game->player.pos.x = file->player_col + 0.5;
	game->player.pos.y = file->player_row + 0.5;
	game->player.orientation = file->player_view;
	set_player_dir(game);

	/* colocar as texturas no/so/we/ea depois 
		tbm falta o char player_view*/
	return (0);
}

int	init_win(t_game *game)
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
	return (0);
}
// int	init_hooks(t_game *game)
// {
// 	/*pensar na possibilidade de juntar esses, pra main não passar de 25 linhas*/
// 	mlx_loop_hook(...);
// 	mlx_key_hook(...);
// 	mlx_cursor_hook(...);
// }
