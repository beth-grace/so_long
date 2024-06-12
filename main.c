/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:23:52 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/12 18:59:45 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	window_closed(void)
{
	exit(0);
}

int	keykey(int key_code, t_so_long *game)
{
	if (key_code == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

void	gg(t_so_long *counter, t_so_long *game);
//if all colewctables are achieved and on the exit tile, then printf gg ig
int main(int argc, char *argv[])
{
	t_so_long	game;

	if (argc != 2)
		return (1);
	game.mlx = mlx_init();
	map_size(&game, argv[1]);
	read_map(&game, argv[1]);
	put_images(&game);
	game.win = mlx_new_window(game.mlx, game.height * 64, game.width * 64, "stuffz");
	map_gen(&game);
	mlx_key_hook(game.win, keykey, &game);
	mlx_hook(game.win, 17, 1L << 5, &window_closed, NULL);
	mlx_loop(game.mlx);
}
