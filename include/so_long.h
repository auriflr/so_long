/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:19:08 by babyf             #+#    #+#             */
/*   Updated: 2025/09/30 16:07:51 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
#define SO_LONG

/* # include <mlx.h> to download */
# include "../mlx2/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/lib/libft.h"
# include "../libft/lib/ft_printf.h"
# include "../libft/lib/get_next_line.h"

/* The player’s goal is to collect all collectibles on the map 
and then escape by choosing the shortest possible route. 
Maps are built from characters:
1 for walls
0 for (walking) spaces
C for Collectibles
P for Player
E for exit 
Controls use the keyboard:
W for moving up
S for moving down
D for moving to the right
A for moving to the left
ESC to exit */


/* structs */

typedef	struct	s_game
{
	void		*mlx;
	void		*window; /* pointer window */
	void		*map;
	struct s_graphics	*image; /* to change */
	int			collect;
	int			e_counter;
	int			p_counter;
}				t_game;

typedef struct	s_graphics
{
	
}				t_graphics;

/* parsing / error handling */

/* moves */


#endif