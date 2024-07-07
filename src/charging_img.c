/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charging_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:11:48 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/07 16:10:02 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static	void	charge_xpm(t_game *game)
{
	int	x;
	int	y;
	
	game->image.coin = mlx_xpm_file_to_image(game->mlx,COIN,&(x),&(y));
	game->image.player = mlx_xpm_file_to_image(game->mlx,PLAYER,&(x),&(y));
	game->image.wall = mlx_xpm_file_to_image(game->mlx,WALL,&(x),&(y));
	game->image.exit = mlx_xpm_file_to_image(game->mlx,DOOR,&(x),&(y));
	game->image.floor = mlx_xpm_file_to_image(game->mlx,FLOOR,&(x),&(y));
}
static	void	put_img(t_game *game,int x, int y)
{
	char now;
	now = game->map.map[y][x];
	if (now == '1')
		put_wall(game, x, y);
	else if (now == '0')
		put_floor(game, x, y);
	else if (now == 'P')
		put_player(game, x, y);
	else if (now == 'E')
		put_door(game, x, y);
	else if (now == 'C')
		put_coin(game, x, y);
}
void	charg_img(t_game *game)
{
	int x;
	int y;

	y = 0;
	charge_xpm(game);
	while (game->map.map[y])
	{	
		x = 0;
		while (game->map.map[y][x])
		{
			put_img(game, x, y);
			x++;
		}
		y++;
	}
}
