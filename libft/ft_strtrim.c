/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:59:37 by bmilford          #+#    #+#             */
/*   Updated: 2024/03/20 17:49:22 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	loop(char const c, char const *set)
{
	int	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*dest;

	start = 0;
	while (s1)
	{
		if (loop(s1[start], set))
			start++;
		else
			break ;
	}
	end = ft_strlen(s1) - 1;
	if (end < 0)
		end = 0;
	while (s1)
	{
		if (loop(s1[end], set))
			end--;
		else
			break ;
	}
	dest = ft_substr(s1, start, end - start + 1);
	return (dest);
}
