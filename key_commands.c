/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:24:44 by beefie            #+#    #+#             */
/*   Updated: 2024/06/19 20:10:55 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycheck(int key_code, t_so_long *game)
{
	int	pot_y;
	int	pot_x;

	pot_y = game->ylocation;
	pot_x = game->xlocation;
	if (key_code == ESCAPE)
		game_closed(game);
	else if (key_code == KEY_W)
		pot_y -= 1;
	else if (key_code == KEY_A)
		pot_x -= 1;
	else if (key_code == KEY_S)
		pot_y += 1;
	else if (key_code == KEY_D)
		pot_x += 1;
	else
		return (0);
	moving(game, pot_y, pot_x);
	return (0);
}

void	moving(t_so_long *game, int pot_y, int pot_x)
{
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (game->map[pot_y][pot_x] == '1')
		ft_printf("Error!:\nWALL DUMB DUMB\n");
	else
	{
		old_tile(game);
		game->ylocation = pot_y;
		game->xlocation = pot_x;
		player_position(game);
	}
}

void	player_position(t_so_long *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player,
		game->xlocation * 64, game->ylocation * 64);
	if (game->map[game->ylocation][game->xlocation] == 'C')
	{
		game->counter--;
		ft_printf("The egg counter is :%d\n", game->counter);
		game->map[game->ylocation][game->xlocation] = '0';
	}
	else if (game->map[game->ylocation][game->xlocation] == 'E'
		&& game->counter == 0)
		game_closed(game);
}

void	old_tile(t_so_long *game)
{
	if (game->map[game->ylocation][game->xlocation] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			game->xlocation * 64, game->ylocation * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			game->xlocation * 64, game->ylocation * 64);
}
