/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upnmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:00:24 by babyf             #+#    #+#             */
/*   Updated: 2025/11/12 18:08:17 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    update_position(int keysym, t_game *game, int *new_x, int *new_y)
{
    *new_x = game->p_x;
    *new_y = game->p_y;
    if (keysym == UP && (*new_y + 1) != '1')
        *new_x -= 1;
    if (keysym == DOWN && (*new_y + 1) != '1')
        *new_x += 1;
    if (keysym == LEFT && (*new_x + 1) != '1')
        *new_y -= 1;
    if (keysym == RIGHT && (*new_x + 1) != '1')
        *new_y += 1;
} 
void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free(game);
	game->window = mlx_new_window(game->mlx, 
					(TILESIZE * game->rows), 
					(TILESIZE * game->cols), 
					"so long");
	if (!game->window)
		close_game(game, "Error:\nWindow not created.\n");
}

void	create_loop(t_game *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, key_manager, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, destroy_all, game);
	mlx_loop(game->mlx);
}

void move_player(int keysym, t_game *game)
{
    int new_x;
    int new_y;
    
    if (keysym != UP && keysym != DOWN && keysym != LEFT && keysym != RIGHT)
        return ;
    update_position(keysym, game, &new_x, &new_y);
    if (game->map[new_y][new_x] == 'E' && game->score == game->collect)
        close_game(game, "WIN! ⭑.ᐟ\n");
    if (game->map[new_y][new_x] == 'A')
        close_game(game, "LOSS ( ╥ ﹏ ╥)\n");
    else if (game->map[new_y][new_x] == 'E' && game->score != game->collect)
        close_game(game, "HEY! THE CAPTAIN NEEDS ALL THE MAPS! ( ◺˰◿ )\n");
    if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'E')
    {
        game->map[game->p_y][game->p_x] = '0';
        if (game->map[new_y][new_x] == 'C')
            game->score++;
        game->map[new_y][new_x] = 'P';
        game->moves++;
        ft_printf("YOUR MOVES: %d ദ്ദി (ᵔ ᗜ ᵔ)\n", game->moves);
        game->p_x = new_x;
        game->p_y = new_y;
        render_map(game, 1);
    }
}
