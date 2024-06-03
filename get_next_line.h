/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:33:26 by yehara            #+#    #+#             */
/*   Updated: 2024/06/03 22:50:51 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE > 2147483647 || BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// lib
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_string;

// gnl
char		*get_next_line(int fd);

// gnl_utils
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_getc(int fd);
int			ft_putc(t_string *str, char c);

#endif