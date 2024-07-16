/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tingz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:54:56 by beefie            #+#    #+#             */
/*   Updated: 2024/07/16 18:29:38 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_so_long *game, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (game-> width == 0)
			game->width = ft_strlen(line) - 1;
		else if (game->width != (int)ft_strlen(line) - 1)
		{
			ft_printf("Error!\nMap not rectangle dumb dumb!!\n");
			free(line);
			exit(0);
		}
		char_check(game, line);
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	char_check(t_so_long *game, char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == 'C')
			game->counter++;
		else if (line[index] == 'E')
			game->exit_c++;
		else if (line[index] == 'P')
			game->player_c++;
		index++;
	}
}

int	map_wall_check(t_so_long *game)
{
	int	pos_y;
	int	pos_x;

	pos_y = 0;
	while (pos_y < game->height)
	{
		pos_x = 0;
		while (pos_x < game->height)
		{
			if ((pos_y == 0 || pos_y == game->height - 1
					|| pos_x == 0 || pos_x == game->width - 1)
				&& game->map[pos_y][pos_x] != '1')
				return (1);
			pos_x++;
		}
		pos_y++;
	}
	return (0);
}

void	map_char_check(t_so_long *game)
{
	int	i;

	if (game->counter == 0 || game->exit_c != 1 || game->player_c != 1
		|| map_wall_check(game))
	{
		ft_printf("Error!!:\nI Don't Like It >:((\n");
		i = 0;
		while (i < game->height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		exit(1);
	}
}

void	read_map(t_so_long *game, char *file)
{
	int		index;
	int		fd;

	index = 0;
	fd = open(file, O_RDONLY);
	game->map = (char **)malloc((game->height + 1) * sizeof(char *));
	while (index < game->height)
	{
		game->map[index] = get_next_line(fd);
		index++;
	}
	close(fd);
}
