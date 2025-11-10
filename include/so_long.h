/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:19:08 by babyf             #+#    #+#             */
/*   Updated: 2025/11/10 17:39:39 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG
# define SO_LONG

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stddef.h>
# include "../libft/lib/libft.h"
# include "../libft/lib/ft_printf.h"
# include "../libft/lib/get_next_line.h"
# include "../mlx/mlx.h"

# define TILESIZE 32
# define UP 119 
# define DOWN 115
# define LEFT 97
# define RIGHT 100 

/* The player’s goal is to collect all collectibles on the map 
and then escape by choosing the shortest possible route. 
Maps are built from characters:
1 for walls
0 for walking spaces
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
	char				**map;
	char				*file;
	void				*mlx;
	void				*window;
	int					collect;
	int					exit;
	int					player;
	int					p_x;
	int					p_y;
	int					cols;
	int					rows;
	int					height;
	int					width;
	int					tilesize;
	int					score;
	int					moves;
}				t_game;

typedef struct	s_graphics
{
	void	*player;
	void	*collect;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*map;
}				t_graphics;

/* fix files and function library */

/* map parsing / error handling */
void	ft_errormsg(t_game *game, const char *msg);
void	is_enclosed(t_game *game);
void	check_rows(t_game *game);
void	is_rectangular(t_game *game);
void	element_parsing(t_game *game);
void	check_map(t_game *game);

/* map handling  */
int		create_matrix(t_game *game);
int		check_matrix(char **matrix);
int		map_size(t_game *game);
void	free_matrix(char **matrix);
void	read_map(t_game *game);
void	remove_nl(char *line);
void	fill(char **matrix, int x, int y, t_game *game);
void	flood_fill(t_game *game);
char	**fill_map(t_game *game);

/* initialize / create */
void		create_loop(t_game *game);
void		open_window(t_game *game);
t_game		*init_game(void);
// t_game		*create_map(t_game *game);
t_game		*create_struct(t_game *game);
t_graphics	*init_graphics(void);
t_graphics	*create_graph(t_game *game);

/* graphics & moves */
void    set_graphics(t_game *game);
void    put_image(t_game *game, void *image, int x, int y);
void    render_map(t_game *game, int i);
void    update_player_graphics(int keysym, t_game *game);
void    update_position(int keysym, t_game *game, int *new_x, int *new_y);
void	move_player(int keysym, t_game *game);

/* exit */
int		key_manager(int keysym, t_game *game);
int		close_game(t_game *game, const char *err_msg);
void	free_map(t_game *game);
void	free_graphics(t_game *game);


#endif