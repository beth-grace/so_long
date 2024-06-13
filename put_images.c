/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:41:28 by beefie            #+#    #+#             */
/*   Updated: 2024/06/13 20:58:33 by beefie           ###   ########.fr       */
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
				w * 64,h * 64);
			else if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlx,game->win,game->walls,
				w * 64,h * 64);
			else
			{
				game->h = h;
				game->w = w;
				map_gen2(game);
			}
			w++;
		}
		h++;
	}
}

void	map_gen2(t_so_long *game)
{
	int	h;
	int	w;

	h = game->h;
	w = game->w;
	if (game->map[h][w] == 'C')
		mlx_put_image_to_window(game->mlx,game->win,
		game->collectables, w * 64, h * 64);
	else if (game->map[h][w] == 'E')
		mlx_put_image_to_window(game->mlx,game->win,game->exit,
		w * 64, h * 64);
	else if (game->map[h][w] == 'P')
	{
		mlx_put_image_to_window(game->mlx,game->win,game->player,
		w * 64, h * 64);
		game->ylocation = h;
		game->xlocation = w;
		game->map[h][w] = '0';
	}
	else
		char_error(game);
}

void	char_error(t_so_long *game)
{
	ft_printf("Error!'\n'Map has invalid Syntax.'\n'");
	while (game->h)
	{
		free(game->map[game->h--]);
		free(game->map);
	}
}
