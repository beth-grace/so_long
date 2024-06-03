/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:29:15 by bmilford          #+#    #+#             */
/*   Updated: 2024/03/18 18:34:42 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	index;
	int		neg;
	int		out;

	index = 0;
	neg = 1;
	out = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
	{
		neg = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		out = str[index] - '0' + (out * 10);
		index++;
	}
	return (out * neg);
}
