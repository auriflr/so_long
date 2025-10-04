/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:19:08 by babyf             #+#    #+#             */
/*   Updated: 2025/10/04 09:27:17 by babyf            ###   ########.fr       */
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
	struct s_graphics	*image;
	char				**map; /* the map is a matrix */
	char				*file;
	void				*mlx;
	void				*window; /* pointer window */
	int					collect;
	int					e_counter;
	int					p_counter;
	int					row_l;
	int					rows;
	int					height;
	int					width;
	int					p_x;
	int					p_y;
}				t_game;

typedef struct	s_graphics
{
	void	*player;
	void	*collect;
	void	*map;
	void	*wall;
	void	*exit;
}				t_graphics;

/* map parsing / error handling */
int		is_rectangular(t_game *game);
int		is_enclosed(char **map);
int		check_char_cell(t_game *game, int i, int j);
int		map_parsing(t_game *game);
int		check_map(t_game *game);

/* fill map */
void	fill(char **matrix, int x, int y, t_game *game);
void	free_matrix(char **matrix);
int		check_matrix(char **matrix);

/* initialize / create */
void		create_window(t_game *game);
t_game		*init_map(void);
t_game		*create_map(t_game *game);
t_game		*create_struct(t_game *game);
t_graphics	*init_graphics(void);
t_graphics	*create_graph(t_game *game);

/* exit */
void	free_map(t_game *game);
void	free_graphics(t_game *game);
void	close_window(t_game *game);
int		close_game(t_game *game);

/* moves */


#endif