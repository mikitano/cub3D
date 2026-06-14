#ifndef TEST_H
#define TEST_H

#include "MLX42/MLX42.h"
#include "stdio.h" 

typedef struct s_test
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x;
	int			y;
}	t_test;

#endif