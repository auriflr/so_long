/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:47:02 by babyf             #+#    #+#             */
/*   Updated: 2025/10/03 15:17:32 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* free map */
void	free_map(t_game *game)
{
	int	i;

	if (!game)
		return ;
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
			i++;
		}
		free (game->map);
		game->map = NULL;
	}
	if (game->file)
			free(game->file);
	if (game->image)
		free(game->image);
	free(game);
}

/* function to free graphics
use mlbx: mlx_destroy_image() */
void	free_graphics(t_game *game)
{
	if (game->image)
	{
		if (game->image->player)
			mlx_destroy_image(game->mlx, game->image->player);
		if (game->image->collect)
			mlx_destroy_image(game->mlx, game->image->collect);
		if (game->image->wall)
			mlx_destroy_image(game->mlx, game->image->wall);
		if (game->image->exit)
			mlx_destroy_image(game->mlx, game->image->exit);
		if (game->image->map)
			mlx_destroy_image(game->mlx, game->image->map);
	}
}

void	close_window(t_game *game)
{
	free_graphics(game);
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
}

int	close_game(t_game *game)
{
	close_window(game);
	exit(EXIT_SUCCESS);
	return (0);
}
