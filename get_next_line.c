/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:50:45 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/08 13:18:04 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static char *rest;
	int ret;
	char buff[BUFF_SIZE];
	int i;

	i = 0;
	if (fd == -1)
		return (GNL_error);
	ret = read(fd, buff, BUFF_SIZE);
	ft_putendl("a");
	if (ret == 0)
		return (GNL_end);
	if (!(*line = ft_memalloc(BUFF_SIZE + 1)))
		return (0);
	ft_putendl("b");
	/*ft_putnbr(BUFF_SIZE);
	ft_putchar('\n');*/
	while (buff[i] != '\n' && buff[i])
	{
		ft_putchar(*line[i]);
		ft_putchar('\n');
		*line[i] = buff[i];
		i++;
	}
	ft_putendl("c");

	if (buff[i] == '\n')
	{
		ft_putendl("d");
		if (!(rest = ft_memalloc(BUFF_SIZE - i + 1)))
			return (0);
		rest = ft_strcpy(rest, (const char *)buff + i);
	}
	ft_putendl("d");
	if (rest[0])
		ft_putendl(rest);
	return (1);
}
