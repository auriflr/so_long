/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 09:22:41 by babyf             #+#    #+#             */
/*   Updated: 2025/10/16 16:39:06 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	char	**line;

	game->rows = 0;
	game->row_l = 0;
	fd = open(game->file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		if (game->row_l == 0)
			game->row_l == len;
		game->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (game->rows);
}

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
	i = 0;
	close (fd);
	return (game->map);
}

void	read_map(t_game *game)
{
	ft_printf("Analyzing map input...hold steady...\n");
	if (map_size(game) < 0)
	{
		ft_printf("Error:\nMap not found.\n");
		close_game(game);
	}
	if (create_matrix(game) < 0)
	{
		ft_printf("Error:\n Malloc in matrix failed.\n");
		close_game(game);
	}
	if (fill_map(game) == NULL)
	{
		ft_printf("Error:\nError in map reading.\n");
		close_game(game);
	}
	ft_printf("Reading map...\nDone.\n");
}
