/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tingz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beefie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:54:56 by beefie            #+#    #+#             */
/*   Updated: 2024/06/12 16:18:52 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_so_long *game, int fd)
{
	char	*line;
	int		index;

	index = 0;
	fd = open("argc, second arguement",O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		game->width = ft_strlen(line);
		game->height++;
		while (line[index])
		{
			if (line[index] == 'C')
				game->counter++;
			index++;
		}				
		free(line)
	}
	close(fd)

void	read_map(t_so_long *game, int fd, char **map)
{
	int	index;

	index = 0;
	fd = open("idk",O_RDONLY);
	while(index <= game->height)
	{
		*map[index] = get_next_line(fd)
		index++;
		free(map)
	}
	close(fd)



