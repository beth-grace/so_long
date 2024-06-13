/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:23:52 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/13 18:57:02 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	game_closed(t_so_long *game)
{
	int	index;

	index = 0;
	while (index < game->height)
	{
		free(game->map[index]);
		index++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->walls);
	mlx_destroy_image(game->mlx, game->collectables);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->floor);
	exit(0);
}

int main(int argc, char *argv[])
{
	t_so_long	game;

	if (argc != 2)
		return (1);
	game.mlx = mlx_init();
	game.width = 0;
	game.height = 0;
	game.counter = 0;
	map_size(&game, argv[1]);
	read_map(&game, argv[1]);
	put_images(&game);
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "Happy Chickens <33");
	map_gen(&game);
	mlx_key_hook(game.win, keycheck, &game);
	mlx_hook(game.win, 17, 1L << 5, &game_closed, NULL);
	mlx_loop(game.mlx);
}
