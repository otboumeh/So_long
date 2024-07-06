/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:16:19 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/06 16:57:14 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
#include "../mlx/mlx.h"
#include <X11/keysym.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"


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
}               t_player;
 

typedef struct s_game
{
    void	    *mlx;
    void	    *mlx_win;
    t_map       map;
    t_player    player; 
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


#endif