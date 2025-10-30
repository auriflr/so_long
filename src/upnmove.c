/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upnmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:00:24 by babyf             #+#    #+#             */
/*   Updated: 2025/10/30 14:47:28 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    update_player_graphics(int keysym, t_game *game)
{
    if (game->image->player)
        mlx_destroy_image(game->mlx, game->image->player);
    if (keysym == UP)
        game->image->player = mlx_xpm_file_to_image(game->mlx,
        "graphics/player2.xpm", &game->tilesize, &game->tilesize);
    if (keysym == DOWN)
        game->image->player = mlx_xpm_file_to_image(game->mlx, 
        "graphics/player1.xpm", &game->tilesize, &game->tilesize);
    if (keysym == RIGHT)
    {
        game->image->player = mlx_xpm_file_to_image(game->mlx,
        "graphics/player3.xpm", &game->tilesize, &game->tilesize);
        game->image->player = mlx_xpm_file_to_image(game->mlx,
        "graphics/player0.xpm", &game->tilesize, &game->tilesize);
    }
    if (keysym == LEFT) /* not so sure, maybe turn the image */
    {
        game->image->player = mlx_xpm_file_to_image(game->mlx,
        "graphics/player3.xpm", &game->tilesize, &game->tilesize);
        game->image->player = mlx_xpm_file_to_image(game->mlx,
        "graphics/player0.xpm", &game->tilesize, &game->tilesize);
    }
}

void    update_position(int keysym, t_game *game, int *new_x, int *new_y)
{
    *new_x = game->p_x;
    *new_y = game->p_y;
    if (keysym == UP)
        *new_y -= 1;
    if (keysym == DOWN)
        *new_y += 1;
    if (keysym == LEFT)
        *new_x -= 1;
    if (keysym == RIGHT)
        *new_x += 1;
    update_player_graphics(keysym, game);
}

void move_player(int keysym, t_game *game)
{
    int new_x;
    int new_y;
    
    if (keysym != UP && keysym != DOWN && keysym != LEFT && keysym != RIGHT)
        return ;
    update_position(keysym, game, &new_x, &new_y);
    if (game->map[new_x][new_y] == 'E' && game->score == game->collect)
        close_game(game, "WIN! ⭑.ᐟ\n");
    if (game->map[new_x][new_y] == 'A')
        close_game(game, "LOSS (╥﹏╥)\n");
    else if (game->map[new_x][new_y] == 'E' && game->score != game->collect)
        close_game(game, "HEY! THE CAPTAIN NEEDS ALL THE MAPS! ( ◺˰◿ )\n");
    if (game->map[new_x][new_y] != '1' && game->map[new_x][new_y] != 'E')
    {
        game->map[game->p_y][game->p_x] = '0';
        if (game->map[new_x][new_y] == 'C')
            game->score++;
        game->map[new_y][new_x] = 'P';
        game->moves++;
        ft_printf("YOUR MOVES: %d ദ്ദി(ᵔᗜᵔ)\n");
        game->p_x = new_x;
        game->p_y = new_y;
        render_map(game, 1);
    }
}
