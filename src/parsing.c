/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:25:16 by babyf             #+#    #+#             */
/*   Updated: 2025/11/13 12:16:57 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* checks the shape of the map */
void	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (i < game->rows - 1)
	{
		len = ft_strlen(game->map[i]);
		if (len != game->cols)
			ft_errormsg("Map is not a valid shape.\n");
		i++;
	}
	/*
	if (game->cols == game->rows)
		ft_errormsg(game, "Map is a square.\n");
	*/
}

/* checks that the borders of the map are all walls 
and that the line ends properly 
TEST */
void	is_closed(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->cols - 1] != '1')
			close_game(game, "Rows borders are not walls.\n");
		i++;
	}
	while (i < game->cols)
	{
		if (game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
			close_game(game, "Columns borders are not walls.\n");
		i++;
	}
	if (game->map[game->rows - 1][i] != '\0' && \
		game->map[game->rows - 1][i] != '\n')
		ft_errormsg("Invalid map.\n");
}

/* checks that the last row is walls && the line ends properly */
/* void	check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->cols)
	{
		if (game->map[game->rows - 1][i] != '1')
			ft_errormsg(game, "Invalid map.\n");
		i++;
	}
	if (game->map[game->rows - 1][i] != '\0' && \
		game->map[game->rows - 1][i] != '\n')
		ft_errormsg(game, "Invalid map.\n");
} */ 

/* checks if the elements inside the map are placed correctly */
void	element_parsing(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->player++;
				game->p_x = j;
				game->p_y = i;
			}
			else if (game->map[i][j] == 'C')
				game->collect++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				close_game(game, "Invalid element.\n");
			j++;
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	is_closed(game);
	/* check_rows(game); */
	is_rectangular(game);
	element_parsing(game);
	if (game->exit != 1 || game->collect < 1 || game->player != 1)
			ft_errormsg( "Invalid element quantity.\n");
}