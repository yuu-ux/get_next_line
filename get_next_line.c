/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:33:23 by yehara            #+#    #+#             */
/*   Updated: 2024/06/03 22:38:57 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	t_string	ret;
	int			c;

	ret = (t_string){NULL, 0, 0};
	while (1)
	{
		c = ft_getc(fd);
		if (c == -2)
		{
			free(ret.str);
			return (NULL);
		}
		if (c == EOF)
			break ;
		c = ft_putc(&ret, c);
		if (c == -1)
			return (NULL);
		if (c == '\n')
			break ;
	}
	if (ret.len > 0)
		c = ft_putc(&ret, '\0');
	if (c == -1)
		return (NULL);
	return (ret.str);
}
