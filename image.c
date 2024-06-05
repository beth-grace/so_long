/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:21:27 by beefie            #+#    #+#             */
/*   Updated: 2024/06/05 20:48:34 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image()
{
	t_so_long	oolong;

	oolong.mlx = mlx_init();
	//oolong.image = mlx_new_image(oolong.mlx, 200, 100);
	oolong.image.image = mlx_xpm_file_to_image(oolong.mlx,
		"assets/Egg_item.xpm", &oolong.image.width, &oolong.image.height);
	mlx_put_image_to_window(oolong.mlx, oolong.windoe, oolong.image.image, 150, 50);
}
