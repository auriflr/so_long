/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:06:29 by babyf             #+#    #+#             */
/*   Updated: 2025/11/13 14:52:26 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    set_graphics(t_game *game)
{
    int img_size;

    img_size = TILESIZE;
    game->graphics->player = mlx_xpm_file_to_image(game->mlx, "graphics/player.xpm", &img_size, &img_size);
    if (!game->graphics->player)
        ft_errormsg("Player graphics was not properly loaded.\n");
    game->graphics->exit = mlx_xpm_file_to_image(game->mlx, "graphics/exit.xpm", &img_size, &img_size);
    if(!game->graphics->exit)
        ft_errormsg("Exit graphics was not properly loaded.\n");
    game->graphics->floor = mlx_xpm_file_to_image(game->mlx, "graphics/floor.xpm", &img_size, &img_size);
    if (!game->graphics->floor)
        ft_errormsg("Floor graphics was not properly loaded.\n");
    game->graphics->collect = mlx_xpm_file_to_image(game->mlx, "graphics/collect.xpm", &img_size, &img_size);
    if (!game->graphics->collect)
        ft_errormsg("Collect graphics was not properly loaded");
    game->graphics->wall = mlx_xpm_file_to_image(game->mlx, "graphics/walls.xpm", &img_size, &img_size);
    if (!game->graphics->wall)
        ft_errormsg("Wall graphics was not loaded properly.\n");
}

void    put_graphics(t_game *game, void *graphics, int x, int y)
{
    if (!graphics)
        close_game(game, "graphics loading went wrong.\n");
    mlx_put_image_to_window(game->mlx, game->window, graphics, (y * TILESIZE), (x * TILESIZE));
}

void    render_map(t_game *game, int i)
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
                put_graphics(game, game->graphics->wall, x, y);
            if (game->map[x][y] == '0')
                put_graphics(game, game->graphics->floor, x, y);
            if (game->map[x][y] == 'C')
                put_graphics (game, game->graphics->collect, x, y);
            if (game->map[x][y] == 'E')
                put_graphics(game, game->graphics->exit, x, y);
            if (game->map[x][y]== 'P')
                put_graphics(game, game->graphics->player, x, y);
            y++;
        }
        x++;
    }
}
