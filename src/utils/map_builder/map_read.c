/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:29:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/12 17:52:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(int32_t fd)
{
	int32_t	buffer_len;
	char	*row;
	char	*buffer;

	buffer_len = 1;
	row = ft_calloc(1,sizeof(char));
	buffer = ft_calloc(BUFFERSIZE + 1, sizeof(char));
	while ((buffer_len > 0))
	{
		buffer = read(fd, buffer, BUFFERSIZE);
		if (buffer < 0)
			free (buffer);
		if (buffer == 0)
			return (row);
		buffer[buffer_len] = '\0';
		row = ft_strjoin(row, buffer);
	}
	close(fd);
	return (row);
}
