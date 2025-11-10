/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:06:29 by babyf             #+#    #+#             */
/*   Updated: 2025/11/10 13:10:54 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    set_graphics(t_game *game)
{
    int img_size;

    img_size = TILESIZE;
    game->image->player = mlx_xpm_file_to_image(game->mlx, "graphics/player4.xpm", &img_size, &img_size);
    if (!game->image->player)
        ft_errormsg(game, "Player image was not properly loaded.\n");
    game->image->exit = mlx_xpm_file_to_image(game->mlx, "graphics/exit.xpm", &img_size, &img_size);
    if(!game->image->exit)
        ft_errormsg(game, "Exit image was not properly loaded.\n");
    game->image->floor = mlx_xpm_file_to_image(game->mlx, "graphics/floor.xpm", &img_size, &img_size);
    if (!game->image->floor)
        ft_errormsg(game, "Floor image was not properly loaded.\n");
    game->image->collect = mlx_xpm_file_to_image(game->mlx, "graphics/collect.xpm", &img_size, &img_size);
    if (!game->image->collect)
        ft_errormsg(game, "Collect image was not properly loaded");
    game->image->wall = mlx_xpm_file_to_image(game->mlx, "graphics/walls.xpm", &img_size, &img_size);
    if (!game->image->wall)
        ft_errormsg(game, "Wall image was not loaded properly.\n");
}

void    put_image(t_game *game, void *image, int x, int y)
{
    if (!image)
        close_game(game, "Image loading went wrong.\n");
    mlx_put_image_to_window(game->mlx, game->window, image, (y * TILESIZE), (x * TILESIZE));
}

void    render_map(t_game *game, int i)
{
    int x;
    int y;

    y = 0;
    if (i == 0)
        set_graphics(game);
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                put_image(game, game->image->wall, x, y);
            if (game->map [y][x] == '0')
                put_image(game, game->image->floor, x, y);
            if (game->map [y][x] == 'C')
                put_image (game, game->image->collect, x, y);
            if (game->map [y][x] == 'E')
                put_image(game, game->image->exit, x, y);
            if (game->map[y][x] == 'P')
                put_image(game, game->image->player, x, y);
            x++;
        }
        y++;
    }
}

/*void    render_map(t_game *game, int i)
{
    int x;
    int y;

    x = 0;
    if (i == 0)
        set_graphics(game);
    while (game->map[x])
    {
        y = 0;
        while (game->map[x][y])
        {
            if (game->map[x][y] == '1')
                put_image(game, game->image->wall, x, y);
            if (game->map [x][y] == '0')
                put_image(game, game->image->floor, x, y);
            if (game->map [x][y] == 'C')
                put_image (game, game->image->collect, x, y);
            if (game->map [x][y] == 'E')
                put_image(game, game->image->exit, x, y);
            if (game->map[x][y] == 'P')
                put_image(game, game->image->player, x, y);
            y++;
        }
        x++;
    }
}*/

/* non chiude con X o con ESC */