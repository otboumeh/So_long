/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:33:02 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/25 10:23:45 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	putstr(char *str, int count)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		count = count + 6;
		return (count);
	}
	while (str[i])
	{
		count = print_char(str[i], count);
		i++;
	}
	return (count);
}

int	putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		count = print_char('-', count);
		count = putstr("2147483648", count);
		return (count);
	}
	else if (n < 0)
	{
		count = print_char('-', count);
		n = -n;
		count = putnbr(n, count);
	}
	else if (n > 9)
	{
		count = putnbr(n / 10, count);
		count = putnbr(n % 10, count);
	}
	else
		count = print_char(n + 48, count);
	return (count);
}

int	putnbr_pos(unsigned int n, int count)
{
	if (n == 2147483647)
	{
		count = print_char('2', count);
		count = putnbr(147483647, count);
	}
	else if (n > 9)
	{
		count = putnbr(n / 10, count);
		count = putnbr(n % 10, count);
	}
	else
		count = print_char(n + 48, count);
	return (count);
}
