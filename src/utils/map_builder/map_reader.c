/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:29:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/22 14:38:29 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_reader(int32_t fd)
{
	int32_t	buffer_len;
	char	*row;
	char	*buffer;

	buffer_len = 1;
	row = ft_calloc(1,sizeof(char));
	buffer = ft_calloc(BUFFERSIZE + 1, sizeof(char));
	while ((buffer_len > 0))
	{
		buffer_len = read(fd, buffer, BUFFERSIZE);
		if (buffer < 0)
			free (buffer);
		if (buffer == 0)
			return (row);
		buffer[buffer_len] = '\0';
		ft_printf("buffer before ft_strjoin = %s\n", buffer[buffer_len]);
		row = ft_strjoin(row, buffer);
	}
	close(fd);
	return (row);
}
