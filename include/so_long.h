/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:19:08 by babyf             #+#    #+#             */
/*   Updated: 2025/10/01 11:34:33 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG
# define SO_LONG

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/lib/libft.h"
# include "../libft/lib/ft_printf.h"
# include "../libft/lib/get_next_line.h"
# include "../mlx2/mlx.h"

# define TILESIZE 32 /* eventually change to 64 for more details */
# define UP 13 /* 119 for linux */
# define DOWN 1 /* 115 for linux */
# define LEFT 0 /* 97 for linux */
# define RIGHT 2 /* 100 for linux */

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
	char		**map; /* the map is a matrix */
	void		*mlx;
	void		*window; /* pointer window */
	struct s_graphics	*image; /* to change */
	int			collect;
	int			e_counter;
	int			p_counter;
	int			p_x;
	int			p_y;
}				t_game;

typedef struct	s_graphics
{
	
}				t_graphics;

/* map parsing / error handling */
int		is_rectangular(t_game *game);
int		is_enclosed(char **map);
int		check_char_cell(t_game *game, int i, int j);
int		map_parsing(t_game *game);
int		check_map(t_game *game);

/* fill map */


/* moves */


#endif