/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complimets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:42:56 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/25 13:08:29 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	player_initial_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.y = y;
				game->player.x = x;
				game->map.map[y][x] == '0';
			}
			x++;
		}
		y++;
	}
}

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->image.exit);
	mlx_destroy_image(game->mlx, game->image.coin);
	mlx_destroy_image(game->mlx, game->image.floor);
	mlx_destroy_image(game->mlx, game->image.player);
	ft_free(game);
	exit(EXIT_SUCCESS);
}
