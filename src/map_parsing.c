/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:03:59 by babyf             #+#    #+#             */
/*   Updated: 2025/10/17 11:33:30 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* checks the shape of the map */
void	is_rectangular(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->rows - 1)
	{
		if ((size_t) ft_strlen(game->map[i] -1 != game->cols))
			ft_errormsg(game, "Map is not rectangular.");
		i++;
	}
	if (game->cols == game->rows)
		ft_errormsg(game, "Map is a square.");
}

/* checks that all the outside corners of the map are walls */
void		is_enclosed(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (i == 0 || i == (game->rows - 1))
				if (game->map[i][j] != '1')
					ft_errormsg(game, "Map rows borders are not walls.");
			if (j == 0 || j == (game->cols -1))
				if (game->map[i][j] != '1')
					ft_errormsg(game, "Map collons borders are not walls");
			j++;
		}
		i++;
	}
}
/* checks only the rows. Verify redundancy. */
void	check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->cols)
	{
		if (game->map[game->rows - 1] != '1')
			ft_errormsg(game, "Invalid map.");
		i++;
	}
	if (game->map[game->rows -1][i] != '\0' && \
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
			if (game->map[i][j] == 'P') /* update condition so it checks it's 1 P */
			{
				game->player++;
				game->p_x = i;
				game->p_y = j;
			}
			else if (game->map[i][j] == 'C')
				game->collect++;
			else if (game->map[i][j] == 'E') /* update condition so it checks it's 1 E */
				game->exit++;
			else if (game->map[i][j] != '1' && game->map != '0')
				ft_errormsg(game, "Invalid element.");
		}
	}
}

void	check_map(t_game *game)
{
	is_enclosed(game);
	rows_check(game);
	is_rectangular(game);
	element_parsing(game);
	if (game->exit != 1 || game->collect < 1 || game->player != 1)
	{
		/* free maps */
		ft_errormsg(game, "Too many players or exit, or too few collectibles.");
	}
}