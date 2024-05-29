/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:33:20 by yehara            #+#    #+#             */
/*   Updated: 2024/05/29 20:47:28 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	n;

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

int	ft_putc(t_string *str, char c)
{
	char	*new_str;

	if (str->str == NULL || str->len + 1 >= str->capa)
	{
		if (str->capa > 0)
			str->capa *= 2;
		else
			str->capa = 2;
		new_str = malloc(str->capa * sizeof(char));
		if (!new_str)
			return (-1);
		if (str->str != NULL)
		{
			ft_memcpy(new_str, str->str, str->len * sizeof(char));
			free(str->str);
		}
		str->str = new_str;
	}
	str->str[str->len] = c;
	str->len++;
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
