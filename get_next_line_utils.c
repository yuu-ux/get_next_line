/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:33:20 by yehara            #+#    #+#             */
/*   Updated: 2024/06/01 02:17:11 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static ssize_t	n;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (-1);
		if (n == 0)
			return EOF;
		bufp = buf;
	}
	n--;
	return ((unsigned char) *bufp++);
}

int	ft_putc(t_string *str, char c)
{
	char	*new_str;

	if (str->str == NULL || str->len + 1 > str->capa)
	{
		size_t capa;

		if (str->capa > 0)
			capa = str->capa * 2;
		else
			capa = 2;
		new_str = malloc(capa);
		if (!new_str)
			return (-1);
		ft_memcpy(new_str, str->str, str->len);
		free(str->str);
		str->str = new_str;
		str->capa = capa;
	}
	str->str[str->len++] = c;
	return (c);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buf;
	unsigned char	*str;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	buf = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < n)
	{
		buf[i] = str[i];
		i++;
	}
	return (buf);
}
