/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:33:23 by yehara            #+#    #+#             */
/*   Updated: 2024/06/01 02:36:04 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	t_string	ret;
	int		c;

	ret = (t_string){NULL, 0, 0};
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		c = ft_putc(&ret, c);
		if (c == EOF || c == '\n')
			break ;
	}
	if (ret.len > 0)
		ft_putc(&ret, '\0');
	return (ret.str);
}
