/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:23:52 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/06 17:40:15 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	window_closed(void)
{
	exit(0);
}

int	keykey(int key_code, t_so_long *oolong)
{
	if (key_code == ESCAPE)
	{
		mlx_destroy_image(oolong->mlx, oolong->image.image);
		mlx_destroy_window(oolong->mlx, oolong->win);
		exit(0);
	}
	return (0);
}

int main(void)
{
	t_so_long	oolong;

	oolong.mlx = mlx_init();
	oolong.win = mlx_new_window(oolong.mlx, 800, 600, "stuffz");
	oolong.image.image = mlx_xpm_file_to_image(oolong.mlx,
		"assets/Grass.xpm", &oolong.image.width, &oolong.image.height);
	mlx_put_image_to_window(oolong.mlx, oolong.win, oolong.image.image, 150, 50);
	mlx_hook(oolong.win, 17, 1L << 5, &window_closed, NULL);
	mlx_key_hook(oolong.win, keykey, &oolong);
	mlx_loop(oolong.mlx);
}
