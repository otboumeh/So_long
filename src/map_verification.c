/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshiki <tshiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:48:01 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/23 15:33:04 by tshiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//verification si il y'a un .ber a la fin de l'argument
void	check_extension(char *argv1, t_game *game)
{
	int	i;

	i = ft_strlen(argv1);
	if (ft_strncmp(&argv1[i - 4], ".ber", 4) != 0)
	{
		ft_error("\nError\n Map file must have .ber extension \n");
	}
	game->map.path = argv1;
}

//calculer la longeur 'y' et la largeur 
//'x' de la map et verification si la map est rectangulaire. 
void	get_len(t_game *game)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open (game->map.path, O_RDONLY);
	if (fd < 0)
		ft_error("\nprobleme to open the map\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("\nempty Map\n");
	game->map.x = ft_strlen(line) - 1;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) != game->map.x)
			ft_error("\nMap is irregular on x\n");
		game->map.y++;
		temp = line;
		line = get_next_line(fd);
		free(temp);
	}
	close(fd);
}
