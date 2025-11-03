/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:47:02 by babyf             #+#    #+#             */
/*   Updated: 2025/11/03 18:18:07 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/* OK */
/* easy function for error messages */
void	ft_errormsg(t_game *game, const char *msg)
{
	ft_printf("Error:\n %s\n", msg);
	if (game->map)
		free (game->map);
}

int	key_down(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_game(game, "Quit by user.\n");
	else
		move_player(keysym, game);
	return (0);
}

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
	if (game->image)
		free(game->image);
	free(game);
}

/* function to free graphics */
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

int	close_game(t_game *game, const char *err_msg)
{
	if (err_msg)
		ft_printf ("Error:\n %s\n", err_msg);
	if (game)
	{
		if (game->image)
			free_graphics(game);
		if (game->mlx)
			mlx_loop_end(game->mlx);
		if (game->mlx && game->window)
		{
			mlx_destroy_window(game->mlx, game->window);
			game->window = NULL;
		}
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free (game->mlx);
			game->mlx = NULL;
		}
		free_map(game);
	}
	exit (EXIT_FAILURE);
	return (0);
}
