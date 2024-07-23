/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshiki <tshiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:59:46 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/23 15:31:00 by tshiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_error(char *message)
{
	ft_printf("%s", message);
	exit(1);
}
void	check_arg_number(int argc)
{
	if (argc != 2)
		ft_error("\n Invalid arguments number\n");
}
void	ft_free(t_game *game)
{
	int	y;

	y = -1;
	while (game->map.map[++y])
		free(game->map.map[y]);
	free(game->map.map);
	game->map.map = NULL;
}
void	verification_of_playalibtly(t_game *game)
{
	if (game->player.coin != game->player.flous || game->player.exit == false)
	{
		ft_error("\n map is unplayable \n");
	}
	ft_free(game);
}