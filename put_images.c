/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:41:28 by beefie            #+#    #+#             */
/*   Updated: 2024/06/13 01:03:52 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_so_long *game)
{
	int	height;
	int	width;

	game->walls = mlx_xpm_file_to_image(game->mlx,"asset/wall.xpm",
		&height, &width);
	game->collectables =mlx_xpm_file_to_image(game->mlx,"asset/egg.xpm",
		&height, &width);
	game->player = mlx_xpm_file_to_image(game->mlx,"asset/chicken.xpm",
		&height, &width);
	game->exit = mlx_xpm_file_to_image(game->mlx,"asset/exit.xpm",
		&height, &width);
	game->floor = mlx_xpm_file_to_image(game->mlx,"asset/grass.xpm",
		&height, &width);
}

void	map_gen(t_so_long *game)
{
	int	w;
	int	h;

	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			if (game->map[h][w] == '0')
				mlx_put_image_to_window(game->mlx,game->win,game->floor,
					h * 64,w * 64);
			else if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlx,game->win,game->walls,
					h * 64,w * 64);
			else if (game->map[h][w] == 'C')
				mlx_put_image_to_window(game->mlx,game->win,
					game->collectables,h * 64,w * 64);
			else if (game->map[h][w] == 'E')
				mlx_put_image_to_window(game->mlx,game->win,game->exit
					,h * 64,w * 64);
			else if (game->map[h][w] == 'P')
				mlx_put_image_to_window(game->mlx,game->win,game->player,
					h * 64,w * 64);
			//else
				//ft_printf("illegal map, try again!!");
			w++;
		}
		h++;
	}
}

