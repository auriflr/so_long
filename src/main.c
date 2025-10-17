/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:39:57 by babyf             #+#    #+#             */
/*   Updated: 2025/10/17 15:23:48 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* easy function for error messages */
void	ft_errormsg(t_game *game, const char *msg)
{
	ft_printf("Error:\n %s\n", msg);
	if (game->map)
		free (game->map);
}

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
	/* handle images */
}

/* just for testing */
int	main()
{
	/* not sure if allocating memory is gonna be necessary */
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->window = mlx_new_window(game->mlx, 300, 300, "so_long");
	mlx_loop(game->mlx);
	return (0);
}

/* 
int		main(int ac, char **av)
{
	t_game		*game;
	t_graphics	*graphics;

	if (ac == 2)
	{
		if (!ft_strnstr(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
			ft_errormsg(game, "Map must be a .ber file.");
		game = create_map(game);
		if (!game)
			ft_errormsg(game, "Map wasn't created.");
		read_map(game);
		check_map(game);
		create_struct(game);
		create_window(game);
		render_map(game);
		create_loop(game);
		return (0);
	}
	else if (ac != 2)
		ft_erromsg(game, "Program needs two arguments.");
	else
		ft_errormsg(game, "A map is needed to play the game.");
}
*/