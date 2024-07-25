/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:53:51 by otboumeh          #+#    #+#             */
/*   Updated: 2024/07/25 11:42:50 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr1(const char *s, int c);
char	*ft_strjoinn(char	*s1, const char	*s2);
char	*get_next_line(int fd);
char	*excess(char *deposit);
size_t	ft_strlen1(const char *str);
char	*create_line(char *deposit);

#endif
