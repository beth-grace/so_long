/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:50:01 by bmilford          #+#    #+#             */
/*   Updated: 2024/03/19 13:51:40 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	end;

	index = 0;
	end = 0;
	while (dest[index] && index < dstsize)
		index++;
	while (src[end] && index + end + 1 < dstsize)
	{
		dest[index + end] = src[end];
		end++;
	}
	if (index != dstsize)
		dest[index + end] = '\0';
	return (index + ft_strlen(src));
}
