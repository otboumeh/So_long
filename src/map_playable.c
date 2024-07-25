/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:20:26 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/25 10:28:32 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	verification_recursivity(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1' || game->map.map[y][x] == 'X')
		return ;
	if (game->map.map[y][x] == 'C')
		game->player.flous++;
	if (game->map.map[y][x] == 'E')
		game->player.exit = true;
	game->map.map[y][x] = 'X';
	verification_recursivity(game, y + 1, x);
	verification_recursivity(game, y - 1, x);
	verification_recursivity(game, y, x + 1);
	verification_recursivity(game, y, x - 1);
}

void	verification(t_game *game)
{
	verification_recursivity(game, game->player.y, game->player.x);
}
