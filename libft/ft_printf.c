/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:42:23 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/14 17:14:06 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		index;
	int		out;

	index = 0;
	out = 0;
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
			out += checkcase(format[++index], args);
		else
			out += write(1, format + index, 1);
		index++;
	}
	va_end(args);
	return (out);
}

int	checkcase(char cases, va_list args)
{
	if (cases == '%')
		return (ft_putchar_fd('%', 1));
	else if (cases == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (cases == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (cases == 'p')
		return (ft_putptr_fd(va_arg(args, size_t), 1));
	else if (cases == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (cases == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (cases == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1));
	else if (cases == 'x')
		return (ft_puthex_fd(va_arg(args, unsigned int),
				"0123456789abcdef", 1));
	else if (cases == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1));
	return (-1);
}

int	ft_putptr_fd(size_t n, int fd)
{
	int	t;

	t = ft_putstr_fd("0x", fd);
	t += ft_puthex_fd(n, "0123456789abcdef", fd);
	return (t);
}
