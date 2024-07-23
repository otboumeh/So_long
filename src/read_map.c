/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshiki <tshiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:46:47 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/23 15:32:05 by tshiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

 void    read_map(t_game *game)
{
    int     fd;
    int     i;
    char    *line;
    
    fd = open(game->map.path, O_RDONLY);
    if (fd < 0)
        ft_error("\n probleme to open the map \n");
    game->map.map = (char **)malloc(sizeof(char *) * (game->map.y +1)); 
    if (!(game->map.map))
        ft_error("\nerreur de alocation de memoire\n");
    line = get_next_line(fd);
    if (!line)
        ft_error("\n line is empty \n");
    i = 0;
    while (i < game->map.y)
    {
        game->map.map[i] = line;
        line = get_next_line(fd);
        i++;    
    }
    game->map.map[i] = NULL;
       close(fd);     
}
 void    check_perimeters(t_game *game)
{
    int x;
    int y;
    
    x = game->map.x;
    y = game->map.y;
    while (x--)
    {
        if (game->map.map[0][x]!= '1' || game->map.map[y - 1][x] != '1')
            ft_error("\nmap is not closed\n");
    }
    while (y--)
    {
        if (game->map.map[y][0] != '1' || game->map.map[y][game ->map.x - 1] != '1')
            ft_error("\nmap is not closed\n");
    }
} 
 void check_caracs(t_game *game,int x, int y)
{
    if (game->map.map[y][x] !='1' && game->map.map[y][x] !='0'
        && game ->map.map[y][x] != '\n')
        ft_error("Existance of an invalid caracter"); 
}
void    count_thing(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map.map[y])
    {
        x = 0;
        while (game->map.map[y][x])
        {
            if (game->map.map[y][x] == 'P')
                game->map.player++;
            else if (game->map.map[y][x] == 'C')
                game->player.coin++;
            else if (game->map.map[y][x] == 'E')
                game->map.exit++;
            else
                check_caracs(game, x, y);
            x++;
        }
        y++;
    }
    if (game->map.player != 1 || game->map.exit != 1)
        ft_error("Invalid number of player or exit");
    if (game->player.coin < 1)
        ft_error("Invalid number of coins");
}
 