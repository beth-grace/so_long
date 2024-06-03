/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:18:04 by bmilford          #+#    #+#             */
/*   Updated: 2024/03/19 15:23:50 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				indexh;
	size_t				indexn;

	indexh = 0;
	indexn = 0;
	if (!haystack || !needle)
		return (NULL);
	if (needle[0] == '\0' || len < 0)
		return ((char *)haystack);
	while (haystack[indexh] && needle[indexn] != '\0' && indexh < len)
	{
		indexn = 0;
		if (haystack[indexh] == needle[0])
		{
			while (haystack[indexh] == needle[indexn] && indexh < len)
			{
				if (needle[indexn + 1] == '\0')
					return ((char *)haystack + (indexh - indexn));
				indexh++;
				indexn++;
			}
		}
		indexh += 1 - indexn;
	}
	return (NULL);
}
