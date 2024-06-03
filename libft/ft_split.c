/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:24:03 by bmilford          #+#    #+#             */
/*   Updated: 2024/03/19 13:34:40 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	count(const char *s, char c)
{
	int	index;
	int	size;

	index = 0;
	size = 1;
	if (!*s)
		return (0);
	while (s[index] != '\0')
	{
		if (s[index] == c && s[index -1] != c)
		{
			size++;
		}
		index++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**dest;
	int		size;

	index = 0;
	size = 0;
	dest = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!s || !dest)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				size = ft_strlen(s);
			else
				size = ft_strchr(s, c) - s;
			dest[index++] = ft_substr(s, 0, size);
			s += size;
		}
	}
	dest[index] = NULL;
	return (dest);
}
