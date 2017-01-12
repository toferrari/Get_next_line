/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:50:45 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/12 15:14:27 by tferrari         ###   ########.fr       */
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
	char		buff[BUFF_SIZE + 1];
	char		*str;
	int			i;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret == 0 && rest == NULL)
		return (GNL_end);
	buff[ret] = '\0';
	if (fd < 0 || ret < 0)
		return (GNL_error);
	if (rest == NULL)
	{
		str = ft_strnew(BUFF_SIZE);
		str = ft_strcpy(str, buff);
	}
	else
	{
		str = ft_strnew(ft_strlen(rest) + BUFF_SIZE);
		str = ft_strcat(str, rest);
		str = ft_strcat(str, buff);
	}
	*line = ft_strnew(BUFF_SIZE);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		(*line)[i] = str[i];
		i++;
	}
	(*line)[i] = '\0';
	if (str[i] == '\n')
		i++;
	if (ret == 0 && rest == NULL)
		return (GNL_end);
	if (str[i])
	{
		rest = ft_strnew(ft_strlen(str + i));
		rest = ft_strcpy(rest, str + i);
	}
	else
		rest = NULL;
	return (1);
}
