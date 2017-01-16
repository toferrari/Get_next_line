/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:14:57 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/16 15:48:22 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;
	int		ret;

	i = 1;
	if (argc)
		;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		free(line);
		i++;
	}
	return (0);
}
