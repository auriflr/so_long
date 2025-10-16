/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:05:48 by babyf             #+#    #+#             */
/*   Updated: 2025/10/13 17:33:38 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* initialize map (with calloc, so it's set to 0) */
t_game	*init_map(void)
{
	t_game	*game;
	
	game = (t_game *)calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	return (game);
}

/* initialize graphics with calloc */
t_graphics	*init_graphics(void)
{
	t_graphics	*graphics;

	graphics = (t_graphics *)calloc(1, sizeof(t_graphics));
	if (!graphics)
		return (NULL);
	return (graphics);
}

/* create map */
t_game	*create_map(t_game *game)
{
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game = init_map();
	return (game);
}

/* create graphics */
t_graphics	*create_graph(t_game *game)
{
	game->image = (t_graphics *)malloc(sizeof(t_graphics));
	if (!game)
		return (NULL);
	game->image = init_graphics();
	return (game->image);
}

 /* create struct */
t_game	*create_struct(t_game *game)
{
	if (!game)
		return (NULL);
}