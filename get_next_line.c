/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:50:45 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/09 15:51:46 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static char	*rest;
	int			ret;
	char		buff[BUFF_SIZE];
	char		*str;
	int			i;

	ret = read(fd, buff, BUFF_SIZE);
	if (rest != NULL)
	{
		str = ft_strnew(BUFF_SIZE + ft_strlen(rest));
		str = ft_strcat(buff, rest);
		ft_putendl(buff);
	}
	else
		str = ft_strnew(BUFF_SIZE);
	str = buff;
	str[ret] = '\0';
	i = 0;
	*line = ft_strnew(BUFF_SIZE);
	while (str[i] != '\n' && str[i])
	{
		(*line)[i] = str[i];
		i++;
	}
	if (i < BUFF_SIZE)
	{
		rest = ft_strnew(BUFF_SIZE - i);
		ft_strcpy(rest, str + (i + 1));
	}
	return (1);
}
