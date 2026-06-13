/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:40:43 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/13 12:02:54 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "stdio.h" 

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
Adicional: */

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

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t *img;
	uint32_t	x;
	uint32_t	y;

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
	//desenha só um ponto ao centro da tela
	mlx_put_pixel(img, 400, 300, 0xFFFFFFFF);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	{
		printf("ERROR: image to windown\n");
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		return (1);
	}
	
	//Desenhando a Cruz
	x = 350;
	while (x <= 450)
	{
		mlx_put_pixel(img, x, 300, 0xFFFFFFFF);
		x++;
	}
	y = 250;
	while (y <= 350)
	{
		mlx_put_pixel(img, 400, y, 0xFFFFFFFF);
		y++;
	}

	//desenha quadrado
	draw_square(img, 350, 250, 100, 0xFFFFFFFF);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
