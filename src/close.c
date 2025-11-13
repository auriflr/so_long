/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:47:02 by babyf             #+#    #+#             */
/*   Updated: 2025/11/13 14:21:24 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
}

void	free_graphics(t_game *game)
{
	if (game->graphics)
	{
		if (game->graphics->player)
			mlx_destroy_image (game->mlx, game->graphics->player);
		if (game->graphics->collect)
			mlx_destroy_image (game->mlx, game->graphics->collect);
		if (game->graphics->wall)
			mlx_destroy_image (game->mlx, game->graphics->wall);
		if (game->graphics->exit)
			mlx_destroy_image (game->mlx, game->graphics->exit);
		if (game->graphics->floor)
			mlx_destroy_image (game->mlx, game->graphics->floor);
	}
	free(game->graphics);
	game->graphics = NULL;
}

int	key_manager(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_game(game, "Quit by user\n");
	else
		move_player(keysym, game);
	return (0);
}

int	destroy_all(t_game *game)
{
	free_graphics(game);
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game);
	free(game);
	exit(EXIT_SUCCESS);
}

int	close_game(t_game *game, const char *err_msg)
{
	if (err_msg)
		ft_printf("%s\n", err_msg);
	destroy_all(game);
	return (0);
}
