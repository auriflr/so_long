/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:05:48 by babyf             #+#    #+#             */
/*   Updated: 2025/11/12 17:56:29 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_errormsg(t_game *game, const char *msg)
{
	ft_printf("Error:\n %s\n", msg);
	if (game->map)
		free (game->map);
}

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
	game->image = init_graphics();
	if (!game->image)
		close_game (game, "Error:\n Graphics pointer is NULL.\n");
	return (game);
}
