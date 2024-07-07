/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:20:14 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/07 16:14:55 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "solong.h"


void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, close_window, game);
	/* mlx_hook(game->mlx_win, 2, 1, keysym, game); */
        /*  free(game->mlx); */

}

int main(int argc, char **argv)
{
    t_game  game;
    check_arg_number(argc);
    ft_bzero(&game, sizeof(t_game));
    check_extension(argv[1], &game);
     get_len(&game);
     read_map(&game);
    check_perimeters(&game);
    count_thing(&game);
    game.mlx = mlx_init();
    game.mlx_win = mlx_new_window(game.mlx, game.map.x * 100, game.map.y * 100, "So_long");
    hooks(&game);
    charg_img(&game);
    mlx_loop(game.mlx);
}

/* int main(void)
{
    t_game game;
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

    game.mlx = mlx_init();
    game.mlx_win = mlx_new_window(game.mlx, 2600, 800, "My Window");

    img = mlx_xpm_file_to_image(game.mlx, player, &img_width, &img_height);

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
            mlx_put_image_to_window(game.mlx, game.mlx_win, img, 0, 0);
        }

        if (buf == '\n') {
            y++;
            x = 0;
        } else {
            x++;
        }
    }

    close(fd);

    mlx_key_hook(game.mlx_win, handle_input, &game);
    mlx_hook(game.mlx_win, 17, 0, close_window, &game);

    mlx_loop(game.mlx);

    return 0;
} */