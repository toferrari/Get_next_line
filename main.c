/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:14:57 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/08 14:18:40 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libft.h>

int main(int argc, char ** argv)
{
	char *line = NULL;
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (get_next_line(fd, &line));
		ft_putendl(line);
	return (0);
}
