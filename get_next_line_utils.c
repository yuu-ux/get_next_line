/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:33:20 by yehara            #+#    #+#             */
/*   Updated: 2024/06/02 22:24:31 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int fd)
{
	static char		buf[BUFFER_SIZE];
	static char		*bufp;
	static ssize_t	n;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			n = 0;
			return (-2);
		}
		else if (n == 0)
			return (EOF);
		bufp = buf;
	}
	n--;
	return ((unsigned char)*bufp++);
}

int	ft_putc(t_string *str, char c)
{
	char	*new_str;
	size_t	capa;

	if (str->str == NULL || str->len + 1 > str->capa)
	{
		if (str->capa > 0)
			capa = str->capa * 2;
		else
			capa = 2;
		new_str = malloc(capa + 1);
		ft_memset(new_str, 0, capa + 1);
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

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
