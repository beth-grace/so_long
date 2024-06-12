/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmilford <bmilford@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:22 by bmilford          #+#    #+#             */
/*   Updated: 2024/06/12 18:48:02 by beefie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# ifdef LINUX
// LINUX KEYCODES
#  define ESCAPE		0xff1b
#  define KEY_W			0x12
#  define KEY_S			0x20
#  define KEY_A			0x1f
#  define KEY_D			0x21

# else
// MACOS KEYCODES
#  define ESCAPE		0x35
#  define KEY_W			0x0D
#  define KEY_S			0x01
#  define KEY_A			0x00
#  define KEY_D			0x02

#endif

typedef struct s_so_long
{
	int			counter;
	int			height;
	int			width;
	char		**map;
	void		*mlx;
	void		*win;
	void		*walls;
	void		*collectables;
	void		*player;
	void		*floor;
	void		*exit;
}	t_so_long;

void	put_images(t_so_long *game);
void	map_gen(t_so_long *game);
void	map_size(t_so_long *game,char *file);
void	read_map(t_so_long *game, char *file);


#endif
