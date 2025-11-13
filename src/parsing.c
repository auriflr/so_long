/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:25:16 by babyf             #+#    #+#             */
/*   Updated: 2025/11/13 14:03:29 by afloris          ###   ########.fr       */
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
		close_game(game, "Invalid map.\n");
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
		close_game(game, "Invalid element quantity.\n");
}

/* 
==61877== Invalid read of size 1
==61877==    at 0x10E6C5: is_closed (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E988: check_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5D2: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10E6F3: is_closed (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E988: check_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5D2: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Address 0x4c533d4 is 20 bytes inside a block of size 23 free'd
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
==61877==    at 0x10E760: is_closed (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E988: check_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5D2: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Address 0x4c53f69 is 9 bytes inside a block of size 22 free'd
==61877==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x10FBEC: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Block was alloc'd at
==61877==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x110CE1: ft_strjoin (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x110B65: ft_append (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x1108D5: get_next_line (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FBDC: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877== 
==61877== Invalid read of size 1
==61877==    at 0x10E7B1: is_closed (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E988: check_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5D2: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Address 0x4c53f75 is 21 bytes inside a block of size 22 free'd
==61877==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x10FBEC: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Block was alloc'd at
==61877==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x110CE1: ft_strjoin (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x110B65: ft_append (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x1108D5: get_next_line (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FBDC: fill_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10FCA1: read_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5C6: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877== 
==61877== Invalid read of size 1
==61877==    at 0x110647: ft_strlen (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E662: is_rectangular (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E994: check_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5D2: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10E83C: element_parsing (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E9A0: check_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5D2: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10E88C: element_parsing (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E9A0: check_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5D2: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10E8C8: element_parsing (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E9A0: check_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5D2: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10E901: element_parsing (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E9A0: check_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5D2: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10E927: element_parsing (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E9A0: check_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5D2: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==  Address 0x4c533c1 is 1 bytes inside a block of size 23 free'd
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
==61877==    at 0x10F968: render_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5FB: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10F816: render_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5FB: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10F859: render_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5FB: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10F89C: render_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5FB: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10F8DF: render_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5FB: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877==    at 0x10F922: render_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E5FB: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
Quit by user

==61877== Invalid free() / delete / delete[] / realloc()
==61877==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==61877==    by 0x10EE52: free_map (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10F07B: destroy_all (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10F0D0: close_game (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10EFFE: key_manager (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x1114D5: mlx_loop (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10F382: create_loop (in /nfs/homes/afloris/Desktop/so_long/so_long)
==61877==    by 0x10E607: main (in /nfs/homes/afloris/Desktop/so_long/so_long)
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
==61877== 
==61877== HEAP SUMMARY:
==61877==     in use at exit: 0 bytes in 0 blocks
==61877==   total heap usage: 1,599 allocs, 1,607 frees, 699,682 bytes allocated
==61877== 
==61877== All heap blocks were freed -- no leaks are possible
==61877== 
==61877== For lists of detected and suppressed errors, rerun with: -s
==61877== ERROR SUMMARY: 2164 errors from 20 contexts (suppressed: 1 from 1)

*/