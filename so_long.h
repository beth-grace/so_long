/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:22 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/06 17:18:43 by bmilford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <string.h>

# ifdef LINUX
// LINUX KEYCODES
#  define ESCAPE		0xff1b

# else
// MACOS KEYCODES
#  define ESCAPE		0x35

#endif

typedef struct s_sprite
{
	void	*image;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
	t_sprite	image;
}	t_so_long;

#endif
