/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:16:19 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/08 15:41:03 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
#include <stdbool.h>
#include "../mlx/mlx.h"
#include <X11/keysym.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"
#define WALL "texture/wall.xpm"
#define PLAYER "texture/player.xpm"
#define FLOOR "texture/floor.xpm"
#define DOOR "texture/door.xpm"
#define COIN "texture/coin.xpm"


typedef struct s_map
{   
    char    **map;
    char    *path;
    int     x;
    int     y;
    int     player;
    int     exit; 
}               t_map;
 typedef struct s_player
{
    int     coin;
    int     x;
    int     y;
    int     flous;
    bool    exit;
}               t_player;
 
typedef struct s_image
{
    void   *player; 
    void    *floor;
    void    *coin;
    void    *exit;
    void    *wall; 
}               t_image;

typedef struct s_game
{
    void	    *mlx;
    void	    *mlx_win;
    t_map       map;
    t_player    player; 
    t_image     image;
}               t_game;

int     close_window(t_game *data);
int	    handle_input(int keysym, t_game *game);
void	check_extension(char *argv1, t_game *game);
void	get_len(t_game *game);
void	check_arg_number(int argc);
void    save_map(t_game *game);
void    read_map(t_game *game);
void    check_perimeters(t_game *game); 
void	ft_error(char *message);
void    count_thing(t_game *game);
void    check_caracs(t_game *game,int x, int y); 
static	void charge_xpm(t_game *game);
static	void	put_img(t_game *game,int x, int y);
void	put_floor(t_game *game, int x, int y);
void	put_player(t_game *game, int x, int y);
void	put_door(t_game *game, int x, int y);
void	put_wall(t_game *game, int x, int y);
void	put_coin(t_game *game, int x, int y);
void	charg_img(t_game *game);
void	player_initial_position(t_game *game);
void	verification_recursivity(t_game *game, int y, int x);
void	verification(t_game *game);
void	verification_of_playalibtly(t_game *game);
void    ft_free(t_game *game);

#endif