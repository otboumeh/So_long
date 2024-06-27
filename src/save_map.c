/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:09:44 by otboumeh          #+#    #+#             */
/*   Updated: 2024/06/11 12:50:53 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void    save_map(t_game *game)
{
    int     i;
    int     fd;
    char    *line;

    fd = 0;
	fd = open (game->map.path, O_RDONLY);
	if (fd < 0)
		ft_error("probleme to open the map");
	line = get_next_line(fd);
	if (!line)
		ft_error("empty Map");
    
}