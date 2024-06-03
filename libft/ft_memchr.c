/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:52:25 by bmilford          #+#    #+#             */
/*   Updated: 2024/03/19 14:22:13 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*out;

	index = 0;
	out = (unsigned char *)s;
	if (!s && !c)
		return (NULL);
	while (index < n)
	{
		if (out[index] == (unsigned char)c)
			return ((char *)s + index);
		if (out[index] == (unsigned char)c && c == '\0')
			return ((char *)s + index);
		index++;
	}
	return (NULL);
}
