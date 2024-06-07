/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:20:14 by otboumeh          #+#    #+#             */
/*   Updated: 2024/06/05 13:38:38 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "solong.h"

int main(void)
{
    t_game data;
    void *img;
    int img_width = 10;
    int img_height = 30;
    char *player = "texture/player.xpm";
    char *coin = "texture/coin.xpm";
    char *floor = "texture/floor.xpm";
    char *wall = "texture/wall.xpm";
    char *door = "texture/wall.xpm";
    char *map = "maps/map1.ber";
    int fd = open(map, O_RDONLY);
    char buf;
    int x = 0, y = 0;

    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 2600, 800, "My Window");

    img = mlx_xpm_file_to_image(data.mlx, player, &img_width, &img_height);

    if (img == NULL) {
        perror("Failed to load image\n");
        return 1;
    }

    if (fd == -1) {
        perror("Failed to open map file\n");
        return 1;
    }

    while (read(fd, &buf, 1) > 0) {
        if (buf == 'P') {
            mlx_put_image_to_window(data.mlx, data.mlx_win, img, 0, 0);
        }

        if (buf == '\n') {
            y++;
            x = 0;
        } else {
            x++;
        }
    }

    close(fd);

    mlx_key_hook(data.mlx_win, handle_input, &data);
    mlx_hook(data.mlx_win, 17, 0, close_window, &data);

    mlx_loop(data.mlx);

    return 0;
}