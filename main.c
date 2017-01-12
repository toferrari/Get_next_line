/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:14:57 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/12 15:17:08 by tferrari         ###   ########.fr       */
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
	int i;
	int ret;

	i = 1;

	fd = open(argv[1], O_RDONLY);
	/*if (get_next_line(fd, &line) == 1)
		ft_putendl(line);*/
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		/*ft_putstr("line ");
		ft_putnbr(i);
		ft_putendl(" :");*/
		ft_putendl(line);
		/*ft_putstr("nb lettre = ");
		ft_putnbr(ft_strlen(line));
		ft_putendl("\n");*/
		free(line);
		i++;
	}
	return (0);
}
