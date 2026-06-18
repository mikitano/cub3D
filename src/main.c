/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:06:28 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/18 19:06:28 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_square(t_game *game,int x, int y, uint32_t color)
{
	int	x2;
	int	y2;

	x2 = x;
	y2 = y;

	while (y2 < y + 16) //16 é um size tmp, pq 16? ou 16 ou 32 ou 64
	{
		while (x2 < x + 16)
		{
			mlx_put_pixel(game->img, x2, y2, color);
			x2++;
		}
		x2 = x;
		y2++;
	}
}

void	draw_player(t_game *game)
{
	draw_square(game, game->player.pos.x, game->player.pos.y,0x00B6D0E2);
}

void	draw_map(t_game *game, int x, int y, int size, uint32_t color)
{
	int col;
	int	lin;
	int	x2;
	int	y2;

	lin = 0;
	while (game->map.grid[lin])
	{
		col = 0;
		while (game->map.grid[lin][col])
		{
			x2 = x + (col * size);
			y2 = y + (lin * size);
			if(game->map.grid[lin][col] == '1')
				draw_square(game, x2, y2, color);
			else if (game->map.grid[lin][col] == '0')
				draw_square(game, x2, y2, 0xFF000000);
			col++;
		}
		lin++;
	}
	draw_player(game);

}

void	clear_image(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}
void	game_loop(void *param)
{
	t_game *game;

	game = (t_game *)param;

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		game->player.pos.y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->player.pos.x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		game->player.pos.y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->player.pos.x += 5;
	clear_image(game->img);
	draw_map(game, 0, 0, 16, 0xFFFFFFFF);
}
int	main(int argc, char **argv)
{
	t_parser	parser;
	t_file		file;
	t_texture	texture;
	t_game		game;

	init_structs(&parser, &file, &texture);
	if (!check_args(argc, argv, &parser) || !read_file(argv[1], &parser))
	{
		print_error(parser.status);
		clean_all(&parser);
		return (1);
	}
	//--> Resto do progreama aqui !! <--
	if(init_game(&game, &file) > 0)
	{
		/*tmp depois tem que arrumar*/
		mlx_delete_image(game.mlx, game.img);
		mlx_terminate(game.mlx);
		clean_all(&parser);
		return (1);
	}
	draw_map(&game, 0, 0, 16, 0xFFFFFFFF);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.img);
	mlx_terminate(game.mlx);
	
	clean_all(&parser);
	return (0);
}

// int	main(void)
// {
// 	t_game	game;

// 	if (init_game)
// 	mlx = mlx_init(800, 600, "Aprendendo mlx", false);
// 	if (!mlx)
// 	{
// 		printf("ERROR: mlx\n");
// 		return (1);
// 	}
// 	img = mlx_new_image(mlx, 800, 600);
// 	if (!img)
// 	{
// 		printf("ERROR: img\n");
// 		mlx_terminate(mlx);
// 		return (1);
// 	}
// 	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
// 	{
// 		printf("ERROR: image to windown\n");
// 		mlx_delete_image(mlx, img);
// 		mlx_terminate(mlx);
// 		return (1);
// 	}

// 	//desenha quadrado
// 	// draw_square(game.img, game.x, game.y, 100, 0xFFFFFFFF);

// 	//desenha baseado no mapa
// 	draw_map(game, 0, 0, 16, 0xFFFFFFFF);

// 	mlx_loop_hook(game.mlx, game_loop, &game);
// 	mlx_loop(game.mlx);
// 	mlx_delete_image(mlx, img);
// 	mlx_terminate(mlx);
// }
