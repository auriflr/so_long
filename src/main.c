/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:39:57 by babyf             #+#    #+#             */
/*   Updated: 2025/11/10 17:44:48 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/* forse invertire cols e rows */
void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free(game);
	game->window = mlx_new_window(game->mlx, 
					(TILESIZE * game->rows), 
					(TILESIZE * game->cols), 
					"so long");
	if (!game->window)
		close_game(game, "Error:\nWindow not created.\n");
}

int	key_manager(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_game(game, "Quit by user\n");
	else
		move_player(keysym, game);
	return (0);
}

void	create_loop(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, key_manager, game);
	mlx_loop(game->mlx);
}


int		main(int ac, char **av)
{
	t_game		*game;

	if (ac == 2)
	{
		if (!ft_strnstr(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
			ft_errormsg(NULL, "Map must be a .ber file.");
		game = init_game();
		if (!game)
			return(ft_printf("Map wasn't created.\n"), 0);
		game->file = av[1];
		read_map(game);
		ft_printf("parsing OK\n");
		check_map(game);
		ft_printf("map OK\n");
		create_struct(game);
		ft_printf("struct OK\n");
		open_window(game);
		ft_printf("window OK\n");
		render_map(game, 0);
		ft_printf("render OK\n");
		create_loop(game);
		return (0);
	}
	return (ft_printf("Hi, user. You need a map to play the game!"), 1);
}

/* valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map1.ber */