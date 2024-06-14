/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tingz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:54:56 by beefie            #+#    #+#             */
/*   Updated: 2024/06/14 18:38:26 by bmilford         ###   ########.fr       */
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
		if (game-> width == '\0')
			game->width = ft_strlen(line) - 1;
		else if (game->width != (int)ft_strlen(line) - 1)
		{
			ft_printf("Error!\nMap not rectangle dumb dumb!!\n");
			free(line);
			exit(0);
		}
		game->height++;
		char_check(game, line);
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
		index++;
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
