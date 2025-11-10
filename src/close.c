/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:47:02 by babyf             #+#    #+#             */
/*   Updated: 2025/11/10 17:41:41 by afloris          ###   ########.fr       */
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
		ft_printf ("%s\n", err_msg);
	if (game)
	{
		if (game->image)
			free_graphics(game);
		if (game->mlx)
		{
			mlx_loop_end(game->mlx);
			if (game->window)
			{
				mlx_destroy_window(game->mlx, game->window);
				game->window = NULL;
			}
			mlx_destroy_display(game->mlx);
			// free (game->mlx);
			game->mlx = NULL;
		}
		// free_map(game);
	}
	exit (EXIT_FAILURE);
	return (0);
}
