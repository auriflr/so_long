/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:39:57 by babyf             #+#    #+#             */
/*   Updated: 2025/11/12 18:04:44 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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