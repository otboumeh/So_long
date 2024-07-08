/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complimets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:42:56 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/08 15:54:01 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	player_initial_position(t_game *game)
{
	int x;
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
