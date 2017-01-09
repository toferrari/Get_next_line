/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:14:57 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/09 13:21:28 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

int main(int argc, char ** argv)
{
	char *line;
	int fd;
	if (argc)
		;

	fd = open(argv[1], O_RDONLY);
	if (get_next_line(fd, &line) == 1)
		ft_putendl(line);
	return (0);
}
