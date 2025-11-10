/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mread.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 09:22:41 by babyf             #+#    #+#             */
/*   Updated: 2025/11/10 16:24:32 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* OK */
void	remove_nl(char *line)
{
	int	len;

	len = ft_strlen(line);
	while (line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	map_size(t_game *game)
{
	int		fd;
	int		len;
	char	*line;

	game->rows = 0;
	game->cols = 0;
	fd = open(game->file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len == 0)
			return (close_game(game, "Map line lenght is 0.\n"), -1);
		if (game->cols == 0)
			game->cols = len - 1;
		game->rows++;
		free(line);
		line = get_next_line(fd);
	}
	// ft_printf("COLS: %d\n", game->cols);
	// ft_printf("ROWS: %d\n", game->rows);
	close (fd);
	return (game->rows);
}

/* error here */
int	create_matrix(t_game *game)
{
	game->map = (char **)malloc((game->rows + 1) * sizeof(char *));
	ft_printf("Matrix created.\n");
	if (!game->map)
	{
		ft_printf("Matrix failed.\n");
		game->map = NULL;
		return (-1);
	}
	return (0);
}

char	**fill_map(t_game *game)
{
	int		fd;
	int		i;
	char	*line;
	
	i = 0;
	fd = open(game->file, O_RDONLY);
	if (fd < 0)
	{
		free (game->map);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = line;
		remove_nl(game->map[i]);
		i++;
		line = get_next_line (fd);
	}
	game->map[i] = NULL;
	close (fd);
	free (line);
	return (game->map);
}

static void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	read_map(t_game *game)
{
	ft_printf("Analyzing map input...hold steady...\n");
	if (map_size(game) < 0)
		close_game(game, "Map not found.\n");
	if (create_matrix(game) < 0)
		close_game(game, "Malloc in matrix failed.\n");
	if (fill_map(game) == NULL)
		close_game(game, "Error in map reading.\n");
	print_map(game->map);
	ft_printf("Reading map...\nDone.\n");
}
