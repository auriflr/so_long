/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:39:57 by babyf             #+#    #+#             */
/*   Updated: 2025/10/04 09:27:15 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	create_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free(game);
	/*game->window = mlx_new_window(game->mlx, (TILESIZE * game->row_l). (TILESIZE * game->rows), "So Long");*/
	if (!game->window)
	{
		close_game(game);
		ft_printf ("Error: Window not created.\n");
	}
		
}
/* calloc for init */
/* remove new line */

int	main()
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->window = mlx_new_window(game->mlx, 300, 300, "So_long");
	mlx_loop(game->mlx);
	return (0);
}