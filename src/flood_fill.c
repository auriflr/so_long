/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:20:53 by babyf             #+#    #+#             */
/*   Updated: 2025/10/06 15:50:43 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
}

int	check_matrix(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'E' || matrix[i][j] == 'C')
			{
				free_matrix(matrix);
				/* print the matrix */
				return (-1);
			}	
			j++;
		}
		i++;
	}
	return (0);
}

void	fill(char **matrix, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->row_l || y >=game->rows)
		return ;
	if (matrix[x][y] == '1' || matrix[x][y] == 'F')
		return ;
	if (matrix[x][y] == 'E')
	{
		matrix[x][y] = 'F';
		return ;
	}
	matrix[x][y] = 'F';
	fill (matrix, x + 1, y, game);
	fill (matrix, x - 1, y, game);
	fill (matrix, x, y + 1, game);
	fill (matrix, x, y - 1, game);
}

/* to rewrite */
void	flood_fill(t_game *game)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = (char **)malloc((game->rows + 1) * sizeof(char *));
	if (!matrix)
	{
		ft_printf("Error: Flood fill failed.\n");
		close_game(game);
	}
	while (i < game->rows)
	{
		matrix[i] = ft_strdup(game->map[i]);
		if (!matrix[i])
		{
			free_matrix(matrix);
			ft_printf("Error: Flood fill failed.\n");
			close_game(game);
		}
		i++;
	}
	matrix[i] = NULL;
	fill(matrix, game->p_x, game->p_y, game);
	if (check_matrix(matrix) < 0)
	{
		ft_printf("Path not valid\n");
		close_game(game);
	}
	free_matrix(matrix);
}

