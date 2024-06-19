/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:53:18 by beefie            #+#    #+#             */
/*   Updated: 2024/06/19 19:50:26 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_so_long *game)
{
	char	**new_map;
	int		i;

	i = -1;
	new_map = malloc(sizeof(char*) * game->height);
	while (++i < game->height)
		new_map[i] = ft_strdup(game->map[i]);
	return(new_map);
}

int	find_path(t_so_long *game)
{
	char	**new_map;
	int		out;
	int		pos_y;
	int		pos_x;

	pos_y = 0;
	pos_x = 0;
	new_map = copy_map(game);

	while (pos_y <= game->height)
	{
		pos_x = 0;
		while (pos_x <= game->width)
		{
			if (game->map[pos_y][pos_x] == 'P')
				break ;
			pos_x++;
		}
		if (game->map[pos_y][pos_x] == 'P')
			break ;
		pos_y++;
	}
	out = maze(game, new_map, pos_y, pos_x);
	pos_y = game->height - 1;
	while (pos_y >= 0)
		free(new_map[pos_y--]);
	free(new_map);

	return (out);
}

int	maze(t_so_long *game, char **new_map, int pos_y, int pos_x)
{

	if (pos_y < 0 || pos_x < 0)
		return (0);
	if (pos_y > game->height || pos_x > game->width)
		return (0);
	if (new_map[pos_y][pos_x] == '1')
		return (0);
	if (new_map[pos_y][pos_x] == 'E')
		return (1);
	new_map[pos_y][pos_x] = '1';
	return (maze(game, new_map, pos_y + 1, pos_x)
		|| maze(game, new_map, pos_y - 1, pos_x)
		|| maze(game, new_map, pos_y, pos_x + 1)
		|| maze(game, new_map, pos_y, pos_x - 1));
}
