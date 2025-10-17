/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:39:57 by babyf             #+#    #+#             */
/*   Updated: 2025/10/17 11:03:58 by babyf            ###   ########.fr       */
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

int	main(int ac, char **av)
{
	/* not sure if allocating memory is gonna be necessary */
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	if (ac != 2)
		ft_errormsg (game, "Two arguments needed.");
	if (!ft_strnstr(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		ft_errormsg (game, "Map must be a .ber file.");
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->window = mlx_new_window(game->mlx, 300, 300, "so_long");
	mlx_loop(game->mlx);
	return (0);
}
