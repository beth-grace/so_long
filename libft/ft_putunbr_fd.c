/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:10:40 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/19 19:19:36 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	c;
	int		t;

	t = 0;
	if (n <= 9)
	{
		c = n + '0';
		write(fd, &c, 1);
		return (1);
	}
	t = ft_putunbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	t++;
	return (t);
}
