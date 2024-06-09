/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:22 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/10 02:11:17 by beefie           ###   ########.fr       */
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
#  define Key_W			0x12
#  define Key_S>>   >   0x20
#  define Key_A>>   >   0x1f
#  define Key_D>>   >   0x21

# else
// MACOS KEYCODES
#  define ESCAPE		0x35
#  define Key_W>>   >   0x0D
#  define Key_S>>   >   0x01
#  define Key_A>>   >   0x00
#  define Key_D>>   >   0x02

#endif

typedef struct s_sprite
{
	void	*image;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_so_long
{
	int			*counter;
	void		*map;
	void		*mlx;
	void		*win;
	void		*walls;
	void		*collectables;
	void		*player;
	void		*floor;
	void		*exit;
	t_sprite	image;
}	t_so_long;

#endif
