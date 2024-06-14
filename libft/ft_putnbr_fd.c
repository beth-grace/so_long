/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:18:27 by bmilford          #+#    #+#             */
/*   Updated: 2024/04/24 16:52:28 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		t;

	t = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write (fd, "-", 1);
		t++;
	}
	if (!(n <= 9 && n >= 0))
		t += ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	t++;
	return (t);
}
/*
int main()
{
	ft_putnbr_fd( -1,1);
	ft_putnbr_fd( 0,1);
	ft_putnbr_fd(1234,1);
	ft_putnbr_fd( -2134,1);
	ft_putnbr_fd(INT_MIN,1);
}
*/
