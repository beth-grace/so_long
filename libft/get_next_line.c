/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:34:45 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/11 18:36:10 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*stash[256];
	char		*buffy;
	char		*newline;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffy = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffy)
		return (0);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	newline = read_nstash(fd, buffy, stash[fd]);
	stash[fd] = extract_line(newline);
	if (newline && ft_strlen(newline) < 1)
	{
		free (newline);
		newline = 0;
	}
	free (buffy);
	buffy = NULL;
	return (newline);
}

// add content of buffer to the end of the stash
char	*read_nstash(int fd, char *buffy, char *stash)
{
	ssize_t	index;
	char	*hold_temp;

	index = 0;
	while (1)
	{
		index = read(fd, buffy, BUFFER_SIZE);
		if (index == 0)
			break ;
		if (index < 0)
		{
			if (stash)
				free (stash);
			return (NULL);
		}
		buffy[index] = '\0';
		hold_temp = stash;
		stash = ft_strjoin(hold_temp, buffy);
		free(hold_temp);
		if (ft_strchr(buffy, '\n'))
			break ;
	}
	return (stash);
}

char	*extract_line(char *newline)
{
	size_t	index;
	char	*stash;

	index = 0;
	if (!newline)
		return (0);
	while (newline[index] != '\n' && newline[index] != '\0')
		index++;
	if (newline[index] == '\0')
		return (NULL);
	stash = ft_substr(newline, index + 1, ft_strlen(newline) - index);
	if (!stash)
		return (0);
	newline[index + 1] = '\0';
	return (stash);
}
