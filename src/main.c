/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:39:57 by babyf             #+#    #+#             */
/*   Updated: 2025/11/03 16:04:13 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free(game);
	game->window = mlx_new_window(game->mlx, 
					(TILESIZE * game->cols), 
					(TILESIZE * game->rows), 
					"so long");
	if (!game->window)
		close_game(game, "Error:\nWindow not created.\n");
}

void	create_loop(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, key_down, game);
	mlx_hook(game->mlx, 17, 0L, close_game, game);
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
		// if (!game->file)
		// 	close_game(game, "Filename not found\n");
		read_map(game);
		check_map(game);
		create_struct(game);
		open_window(game);
		render_map(game, 0);
		create_loop(game);
		return (0);
	}
	return (ft_printf("Hi, user. You need a map to play the game!"), 1);
}

/* valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map1.ber */