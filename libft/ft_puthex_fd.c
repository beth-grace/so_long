/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:24:29 by bmilford          #+#    #+#             */
/*   Updated: 2024/04/24 15:14:24 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned long n, char *pls, int fd)
{
	int				t;
	unsigned int	base;

	t = 0;
	base = ft_strlen(pls);
	if (n < base && n >= 0)
	{
		write(fd, pls + n, 1);
		return (1);
	}
	t = ft_puthex_fd(n / base, pls, fd);
	write(fd, pls + (n % base), 1);
	t++;
	return (t);
}
