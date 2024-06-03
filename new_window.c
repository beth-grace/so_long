/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:23:52 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/03 19:44:35 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	window_closed(void)
{
	exit(0);
}

int	keykey(int key_code, t_so_long *oolong)
{
	if (key_code == 0x35)
	{
		mlx_destroy_window(oolong->mlx, oolong->windoe);
		exit(0);
	}
	return (0);
}
int main(void)
{
	t_so_long	oolong;

	oolong.mlx = mlx_init();
	oolong.windoe = mlx_new_window(oolong.mlx, 800, 600, "stuffz");
	mlx_hook(oolong.windoe, 17, 1L << 5, &window_closed, NULL);
	mlx_key_hook(oolong.windoe, keykey, &oolong);
	mlx_loop(oolong.mlx);
}
