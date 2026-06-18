/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:40:43 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/13 15:15:02 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "stdio.h"
#include "test.h"

//testando como funciona a mlx42

void test(void *param)
{
	(void)param;
	printf("oi\n");
}

/*int	main(void)
{
	mlx_t	*mlx;

	//mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize)
	mlx = mlx_init(800, 600, "cub3d", true); //testar com false, assim ele não da resize
	if (!mlx)
	return (1);

	mlx_loop_hook(mlx, test, NULL); //"registra" as funções de 'ação', ou no caso funções que rodam nos frames
	
	//void mlx_loop(mlx_t* mlx)
	mlx_loop(mlx); //faz o loop e executa funções da lista que foram registradas por mlx_loop_hook
	mlx_terminate(mlx);
	return (0);
}*/

/*código a seguir para testar/aprender:
Abre a janela.
Cria uma mlx_image_t.
Adiciona a imagem na janela.
Desenha um único pixel branco no centro (400, 300).
Adicional: Desenhar a cruz inteira usando dois loops.
Adicional: Desenha quadrado
Adicional: Desenha baseado no mapa*/


void	draw_square( mlx_image_t *img, int x, int y, int size, uint32_t color)
{
	int	x2;
	int	y2;

	x2 = x;
	y2 = y;

	while (y2 < y + size)
	{
		while (x2 < x + size)
		{
			mlx_put_pixel(img, x2, y2, color);
			x2++;
		}
		x2 = x;
		y2++;
	}
}

void	draw_map( mlx_image_t *img, int x, int y, int size, uint32_t color)
{
	char *map[] =
	{
		"11111",
		"10001",
		"10001",
		"10001",
		"11111",
		NULL
	};
	int col;
	int	lin;
	int	x2;
	int	y2;

	lin = 0;
	while (map[lin])
	{
		col = 0;
		while (map[lin][col])
		{
			x2 = x + (col * size);
			y2 = y + (lin * size);
			if(map[col][lin] == '1')
				draw_square(img, x2, y2, size, color);
			else if (map[col][lin] == '0')
				draw_square(img, x2, y2, size, 0xFF000000);
			col++;
		}
		lin++;
	}
}

// t_test fill_test(mlx_t *mlx, mlx_image_t *img, int x, int y)
// {
// 	t_test	test;

// 	if (!mlx || !img)
// 		return (NULL);
// 	test = malloc(sizeof(t_test));
// 	if (!test)
// 		return (NULL);
// 	test.mlx = mlx;
// 	test.img = img;
// 	test.x = x;
// 	test.y = y;
// 	return (test);
// }

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
	t_test *test;

	test = (t_test *)param;

	if (mlx_is_key_down(test->mlx, MLX_KEY_W))
		test->y -= 5;
		// printf("W\n");
	if (mlx_is_key_down(test->mlx, MLX_KEY_A))
		test->x -= 5;
		// printf("A\n");
	if (mlx_is_key_down(test->mlx, MLX_KEY_S))
		test->y += 5;
		// printf("S\n");
	if (mlx_is_key_down(test->mlx, MLX_KEY_D))
		test->x += 5;
		// printf("D\n");
	clear_image(test->img);
	draw_square(test->img, test->x, test->y, 100, 0xFFFFFFFF);	
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t *img;
	t_test		test;
	// uint32_t	x;
	// uint32_t	y;

	mlx = mlx_init(800, 600, "Aprendendo mlx", false);
	if (!mlx)
	{
		printf("ERROR: mlx\n");
		return (1);
	}
	img = mlx_new_image(mlx, 800, 600);
	if (!img)
	{
		printf("ERROR: img\n");
		mlx_terminate(mlx);
		return (1);
	}
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	{
		printf("ERROR: image to windown\n");
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		return (1);
	}
	
	test.mlx = mlx;
	test.img = img;
	test.x = 350;
	test.y = 250;

	//desenha só um ponto ao centro da tela
	// mlx_put_pixel(img, 400, 300, 0xFFFFFFFF);
	
	//Desenhando a Cruz
	// x = 350;
	// while (x <= 450)
	// {
	// 	mlx_put_pixel(img, x, 300, 0xFFFFFFFF);
	// 	x++;
	// }
	// y = 250;
	// while (y <= 350)
	// {
	// 	mlx_put_pixel(img, 400, y, 0xFFFFFFFF);
	// 	y++;
	// }

	//desenha quadrado
	draw_square(test.img, test.x, test.y, 100, 0xFFFFFFFF);

	//desenha baseado no mapa
	// draw_map(img, 100, 100, 16, 0xFFFFFFFF);

	mlx_loop_hook(mlx, game_loop, &test);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
