/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:41:28 by beefie            #+#    #+#             */
/*   Updated: 2024/06/10 02:08:44 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_so_long *oolong)
{
	int	height;
	int	width;

	oolong->wall = mlx_xpm_file_to_image(oolong.mlx,"assets/??",
		&height, &width);
	oolong->collectable =mlx_xpm_file_to_image(oolong.mlx,"assets/??",
		&height, &width);
	oolong->player = mlx_xpm_file_to_image(oolong.mlx,"assets/??",
		&height, &width);
	oolong->exit = mlx_xpm_file_to_image(oolong.mlx,"assets/??",
		&height, &width);
	oolong->floor = mlx_xpm_file_to_image(oolong.mlx,"assets/??",
		&height, &width);
}

void	map_gen(t_so_long *oolong)
{
	if (map == '0')
		mlx_put_image_to_window(oolong->mlx,oolong->win,oolong->floor,??,??);
	else if (map == '1')
		mlx_put_image_to_window(oolong->mlx,oolong->win,oolong->wall,??,??);
	else if (map == 'C')
		mlx_put_image_to_window(oolong->mlx,oolong->win,oolong->collectable,
			??,??);
	else if (map == 'E')
		mlx_put_image_to_window(oolong->mlx,oolong->win,oolong->exit,??,??);
	else if (map == 'P')
		mlx_put_image_to_window(oolong->mlx,oolong->win,oolong->player,??,??);
}

void	read_map(t_so_long *map)
//read map for the collectable counter
