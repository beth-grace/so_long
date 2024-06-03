/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:05:31 by bmilford          #+#    #+#             */
/*   Updated: 2024/04/24 14:21:29 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (!s)
		return (write(fd, "(null)", 6));
	index = 0;
	while (s[index] != '\0')
		index++;
	return (write(fd, s, index));
}
