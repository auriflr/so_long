/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:03:59 by babyf             #+#    #+#             */
/*   Updated: 2025/10/16 16:49:35 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* checks 1) if map is valid, 2) if the map is technically valid, it checks the shape */
int		is_rectangular(t_game *game)
{
	int		i;
	size_t	len_rows;
	
	if (!game || !game->map || !game->map[0])
		return (ft_printf("Error: Map invalid or empty.\n"), -1);
	len_rows = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len_rows)
			return (ft_printf("Error: Map is not valid.\n"), -1);
		i++;
	}
	return (0);
}

/* checks that all the outside corners of the map are walls */
int		is_enclosed(char **map)
{
	int	i;
	int	len_rows;
	int	last_row;

	i = 0;
	last_row = 0;
	while (map[last_row] != NULL)
		last_row++;
	last_row--;
	while (map[i])
	{
		len_rows = 0;
		while (map[i][len_rows])
		{
			if ((i == 0 || i == last_row) && map[i][len_rows] != '1')
				return (ft_printf("Error: Map must be enclosed in walls.\n"), -1);
			len_rows++;
			if (map[i][0] != '1' || map[i][ft_strlen(map[i])- 1] != '1')
				return (ft_printf("Error: Map must be enclosed in walls.\n"), -1);
			i++;
		}
	}
	return (0);
}

/* checks that the char characters in the map are set as the should
1 P
1 E
C for collectibles (no limit) */
int		check_char_cell(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		if (!game->p_counter)
		{
			game->p_counter++;
			game->p_x = j;
			game->p_y = i;
		}
		else
			return (ft_printf("Error: Too many players.\n"), -1);
	}
	else if (game->map[i][j] == 'E')
	{
		if (!game->e_counter)
			game->e_counter++;
		else
			return(ft_printf("Error: Too many exits.\n"), -1);
	}
	else if (game->map[i][j] == 'C')
		game->collect++;
	return (0);
}

int		map_parsing(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (check_char_cell(game, i, j) < 0)
				return (-1);
			j++;
		}
		i++;
	}
	if (game->p_counter == 0 || game->e_counter == 0 || game->collect == 0)
			return (ft_printf("Error: Missing P, E or C. Check map.\n"), -1);
	return (0);
}

/* in the main */
int		check_map(t_game *game)
{
	if (is_rectangular(game) < 0 || is_enclosed(game->map) < 0 || map_parsing(game) < 0)
		close_game(game, "Error:\nCheck shape, walls and cells.\n");
	/* flood_fill */
	return (0);
}