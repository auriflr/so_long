/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:05:48 by babyf             #+#    #+#             */
/*   Updated: 2025/11/13 12:05:56 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_errormsg(const char *msg)
{
	ft_printf("Error:\n %s\n", msg);
}
// void	ft_errormsg(t_game *game, const char *msg)
// {
// 	ft_printf("Error:\n %s\n", msg);
// 	if (game->map)
// 		free (game->map);
// }

t_game	*init_game(void)
{
	t_game	*game;
	
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	return (game);
}

t_graphics	*init_graphics(void)
{
	t_graphics	*graphics;

	graphics = (t_graphics *)ft_calloc(1, sizeof(t_graphics));
	if (!graphics)
		return (NULL);
	return (graphics);
}

t_game	*create_struct(t_game *game)
{
	if (!game)
		close_game(game, "Error:\n Map struct is NULL\n");
	game->graphics = init_graphics();
	if (!game->graphics)
		close_game (game, "Error:\n Graphics pointer is NULL.\n");
	return (game);
}
