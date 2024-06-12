/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tingz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:54:56 by beefie            #+#    #+#             */
/*   Updated: 2024/06/12 18:54:30 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_so_long *game, char *file)
{
	char	*line;
	int		index;
	int		fd;

	index = 0;
	game->height = 0;
	game->width = 0;
	fd = open(file,O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		game->width = ft_strlen(line);
		game->height++;
		while (line[index])
		{
			if (line[index] == 'C')
				game->counter++;
			index++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	read_map(t_so_long *game, char *file)
{
	int		index;
	int		fd;

	index = 0;
	fd = open(file,O_RDONLY);
	game->map = (char **)malloc((game->height + 1) * sizeof(char *));
	while (index < game->height)
	{
		game->map[index] = get_next_line(fd);
		index++;
	}
	close(fd);
}
