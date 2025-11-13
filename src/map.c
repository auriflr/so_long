/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:02:53 by babyf             #+#    #+#             */
/*   Updated: 2025/11/13 14:08:26 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	remove_nl(char *line)
{
	int	len;

	len = ft_strlen(line);
	while (line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len--;
	}
}

int	map_len(t_game *game)
{
	int		fd;
	int		len;
	char	*line;

	game->rows = 0;
	game->cols = 0;
	fd = open (game->file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen (line);
		if (len == 0)
			return (close_game(game, "Map line lenght is 0.\n"));
		if (game->cols == 0)
			game->cols = len - 1;
		game->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (game->rows);
}

int	create_matrix(t_game *game)
{
	game->map = (char **) malloc((game->rows + 1) * sizeof(char *));
	if (!game->map)
	{
		game->map = NULL;
		return (-1);
	}
	return (0);
}

char	**fill_map(t_game *game)
{
	int 	fd;
	int		i;
	char	*line;

	i = 0;
	fd = open (game->file, O_RDONLY);
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
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close (fd);
	// free(line);
	return (game->map);
}

void	read_map(t_game *game)
{
	ft_printf("Analyzing map input...hold steady...\n");
	if (map_len(game) < 0)
		close_game(game, "Map not found.\n");
	if (create_matrix(game) < 0)
		close_game(game, "Malloc in matrix failed.\n");
	if (fill_map(game) == NULL)
		close_game(game, "Error in map reading.\n");
	ft_printf("Reading map...\nDone.\n");
}

/* 
==61877== Memcheck, a memory error detector
==61877== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==61877== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==61877== Command: ./so_long maps/map4.ber
==61877== 
Analyzing map input...hold steady...
==61877== Invalid read of size 1
==61877==    at 0x110647: ft_strlen (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10F9B6: remove_nl (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FBCE: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Address 0x4c533c0 is 0 bytes inside a block of size 23 free'd
==61877==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x10FBEC: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Block was alloc'd at
==61877==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x110CE1: ft_strjoin (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x110ABD: ft_nl_buf (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x1108BC: get_next_line (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FBDC: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877== 
==61877== Invalid read of size 1
==61877==    at 0x10F9DF: remove_nl (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FBCE: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Address 0x4c533d5 is 21 bytes inside a block of size 23 free'd
==61877==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x10FBEC: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Block was alloc'd at
==61877==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x110CE1: ft_strjoin (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x110ABD: ft_nl_buf (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x1108BC: get_next_line (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FBDC: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877== 
==61877== Invalid write of size 1
==61877==    at 0x10F9CC: remove_nl (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FBCE: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Address 0x4c533d5 is 21 bytes inside a block of size 23 free'd
==61877==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x10FBEC: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Block was alloc'd at
==61877==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x110CE1: ft_strjoin (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x110ABD: ft_nl_buf (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x1108BC: get_next_line (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FBDC: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877== 
*/