/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:20:14 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/25 10:13:36 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, destroy_window, game);
	mlx_hook(game->mlx_win, 2, 1, handler_keys, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_arg_number(argc);
	ft_bzero(&game, sizeof(t_game));
	check_extension(argv[1], &game);
	get_len(&game);
	read_map(&game);
	check_perimeters(&game);
	count_thing(&game);
	player_initial_position(&game);
	verification(&game);
	verification_of_playalibtly(&game);
	read_map(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map.x * 100,
			game.map.y * 100, "So_long");
	hooks(&game);
	charg_img(&game);
	mlx_loop(game.mlx);
	return (0);
}
