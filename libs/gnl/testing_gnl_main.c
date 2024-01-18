/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/17 15:46:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdint.h>

int32_t main(int32_t argc, char **argv)
{
	int32_t	fd;
	char	*gnl_temp;
	int		index;

	index = 0;
	gnl_temp = "";
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		write(1, "fd error", 9);
	else if (argc != 2)
		write(1, "argc error", 11);
	else
	{
		write(1, "fd ok", 5);
		printf("\nReading program: %s\n", argv[0]);
		printf("Reading map file: %s\n", argv[1]);
		printf("gnl_temp = %s", gnl_temp);
		while (gnl_temp = '\0')
		{
			printf("MAP line %i = ", index);
			gnl_temp = get_next_line(fd);
			printf("%s", gnl_temp);
			free(gnl_temp);
			index++;
		}
		close (fd);
		printf("\n\nfd was closed.\n");
	}
	return (0);
}
