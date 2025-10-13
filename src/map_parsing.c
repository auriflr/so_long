/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:03:59 by babyf             #+#    #+#             */
/*   Updated: 2025/10/13 17:00:10 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* checks the shape of the map: must be rectangular */

int		is_rectangular(t_game *game)
{
	int	i;
	size_t len_rows;

	if (!game || !game->map || !game->map[0])
		return (ft_printf("Error:\n Map is not rectangular.\n"), -1);
	len_rows = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		/* might return an error, change strlen in that case */
		if (!ft_strlen(game->map[i]) != len_rows)
			return (ft_printf("Error:\n Map is not valid.\n"), -1);
		i++;
	}
	return (0);
}