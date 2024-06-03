/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:57:59 by bmilford          #+#    #+#             */
/*   Updated: 2024/03/19 15:03:39 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = (ft_strlen(s) - 1);
	while (s[index] && index >= 0)
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index--;
	}
	if ((char)c == '\0' && s[index] == (char)c)
		return ((char *)s + ft_strlen(s));
	return (NULL);
}
