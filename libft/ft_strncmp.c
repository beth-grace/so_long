/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:15:48 by bmilford          #+#    #+#             */
/*   Updated: 2024/03/19 15:30:14 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				index;
	const unsigned char	*str1;
	const unsigned char	*str2;

	index = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (index < n)
	{
		if (s1[index] != s2[index] || !s1[index] || !s2[index])
			return (str1[index] - str2[index]);
		index++;
	}
	return (0);
}
