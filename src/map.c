/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 09:22:41 by babyf             #+#    #+#             */
/*   Updated: 2025/10/13 17:31:24 by babyf            ###   ########.fr       */
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
	char	*line;
	int		len;
	int		fd;

	game->rows = 0;
	game->row_l = 0;
	fd = open(game->file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(line);
	
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
	int	fd;
}
/* char **fill_map(t_game *game)
hint: use fd and get next line */

/* void read_map(t_game *game)
just a check that all the functions work */
