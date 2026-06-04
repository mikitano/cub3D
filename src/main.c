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

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(800, 600, "cub3d", true);
	if (!mlx)
		return (1);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
