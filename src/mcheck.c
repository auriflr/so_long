/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcheck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:03:59 by babyf             #+#    #+#             */
/*   Updated: 2025/11/03 18:13:07 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/* OK */
/* checks the shape of the map */
void	is_rectangular(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->rows - 1)
	{
		if ((int) ft_strlen(game->map[i]) - 1 != game->cols)
			ft_errormsg(game, "Map is not rectangular.");
		i++;
	}
	if (game->cols == game->rows)
		ft_errormsg(game, "Map is a square.");
}

/* checks that all the outside corners of the map are walls */
void	is_enclosed(t_game *game)
{
	/* not solved */
}

/* checks only the rows. */
void	check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->cols)
	{
		if (game->map[game->rows - 1][i] != '1')
			ft_errormsg(game, "Invalid map.");	
		i++;
	}
	if (game->map[game->rows - 1][i] != '\0' && \
		game->map[game->rows - 1][i] != '\n')
			ft_errormsg(game, "Invalid map.");
}

/* element parsing */
void	element_parsing(t_game *game)
{
	int i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->player++;
				game->p_x = i;
				game->p_y = j;
			}
			else if (game->map[i][j] == 'C')
				game->collect++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				ft_errormsg(game, "Invalid element.");
		}
	}
}

/* this one leaks */
void	check_map(t_game *game)
{
	is_enclosed(game);
	check_rows(game);
	is_rectangular(game);
	element_parsing(game);
	if (game->exit != 1 || game->collect < 1 || game->player != 1)
	{
		free_map (game);
		ft_errormsg(game, "Too many players or exit, or too few collectibles.");
	}
}