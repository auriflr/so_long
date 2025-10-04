/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 09:22:41 by babyf             #+#    #+#             */
/*   Updated: 2025/10/04 09:29:50 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	create_matrix(t_game *game)
{
	game->map = (char **)malloc((game->rows + 1) * sizeof(char *));
	if (!game->map)
	{
		game->map = NULL;
		return (-1);
	}
	return (0);
}

/* char **fill_map(t_game *game)
hint: use fd and get next line */

/* void read_map(t_game *game)
just a check that all the functions work */
