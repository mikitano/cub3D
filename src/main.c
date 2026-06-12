/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:40:43 by mkitano           #+#    #+#             */
/*   Updated: 2026/06/04 17:55:24 by mkitano          ###   ########.fr       */
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

int	main(void)
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
}
