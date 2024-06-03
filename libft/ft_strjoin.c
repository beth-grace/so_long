/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:55:05 by bmilford          #+#    #+#             */
/*   Updated: 2024/03/18 18:04:37 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index1;
	int		index2;
	char	*join;

	index1 = 0;
	index2 = 0;
	while (s1[index1] != '\0')
		index1++;
	while (s2[index2] != '\0')
		index2++;
	if (index1 + index2 < 1)
		return (ft_strdup(""));
	join = malloc(((index1 + index2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	index1 = 0;
	while (*s1 != '\0')
		join[index1++] = *s1++;
	while (*s2 != '\0')
		join[index1++] = *s2++;
	join[index1] = '\0';
	return (join);
}
