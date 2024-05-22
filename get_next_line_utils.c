/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:33:20 by yehara            #+#    #+#             */
/*   Updated: 2024/05/22 22:38:15 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	getchar(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	n;

	n = 0;
	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (-1);
		bufp = buf;
	}
	if (--n >= 0)
		return ((unsigned char) *bufp++);
	else
		return (EOF);
}

static int	ft_putc(t_string *str, char c)
{
	if (str->len + 1 >= str->capa)
	{

	}
	str->str[str->len] = c;
	str->len++;
	return (0);
}
