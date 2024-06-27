/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:59:46 by otboumeh          #+#    #+#             */
/*   Updated: 2024/06/11 12:25:04 by otboumeh         ###   ########.fr       */
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
		ft_error("Invalid arguments number");
}