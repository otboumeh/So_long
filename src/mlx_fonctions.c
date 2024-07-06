/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:32:06 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/06 17:24:52 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	handle_input(int keysym, t_game *data)
{
    if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx, data->mlx_win);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        exit(1);
    }
    return (0);
}
int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->mlx_win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
}
