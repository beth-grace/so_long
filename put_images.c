/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:41:28 by beefie            #+#    #+#             */
/*   Updated: 2024/06/11 18:20:39 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_so_long *game)
{
	int	height;
	int	width;

	game->walls = mlx_xpm_file_to_image(game->mlx,"assets1/grass.xpm",
		&height, &width);
	game->collectables =mlx_xpm_file_to_image(game->mlx,"assets1/grass.xpm",
		&height, &width);
	game->player = mlx_xpm_file_to_image(game->mlx,"assets1/grass.xpm",
		&height, &width);
	game->exit = mlx_xpm_file_to_image(game->mlx,"assets1/grass.xpm",
		&height, &width);
	game->floor = mlx_xpm_file_to_image(game->mlx,"assets1/grass.xpm",
		&height, &width);
}

void	map_gen(t_so_long *game)
{
	mlx_put_image_to_window(game->mlx,game->win,game->floor,0,0);
	mlx_put_image_to_window(game->mlx,game->win,game->walls,64,0);
	mlx_put_image_to_window(game->mlx,game->win,game->collectables,
		0,64);
	mlx_put_image_to_window(game->mlx,game->win,game->exit,64,64);
	mlx_put_image_to_window(game->mlx,game->win,game->player,64,128);
}

void	read_map(t_so_long *map);
//read map for the collectable counter
