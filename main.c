/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:23:52 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/11 18:23:17 by beefie           ###   ########.fr       */
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
int main(void)
{
	t_so_long	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 800, 600, "stuffz");
	mlx_hook(game.win, 17, 1L << 5, &window_closed, NULL);
	mlx_key_hook(game.win, keykey, &game);
	put_images(&game);
	map_gen(&game);
	mlx_loop(game.mlx);
}
