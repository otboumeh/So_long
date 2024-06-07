/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:16:19 by otboumeh          #+#    #+#             */
/*   Updated: 2024/06/05 17:46:42 by otboumeh         ###   ########.fr       */
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

typedef struct s_map
{
    char    *path;
}               t_map;

typedef struct s_game
{
    void	*mlx;
    void	*mlx_win;
    t_map   map;

}               t_game;


int close_window(t_game *data);
int	handle_input(int keysym, t_game *data);



#endif