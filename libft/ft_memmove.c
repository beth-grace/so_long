/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:18:12 by bmilford          #+#    #+#             */
/*   Updated: 2024/03/19 13:53:08 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (!src && !dst)
		return (NULL);
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (len > 0)
	{
		len--;
		pdst[len] = psrc[len];
	}
	return (dst);
}
