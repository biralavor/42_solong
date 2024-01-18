/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:24:20 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/18 12:49:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_char	*ft_get_let(char let)
{
	t_char	*def_char;

	def_char = (t_char *)ft_calloc(1, sizeof(t_char));
	if (!def_char)
		return (NULL);
	def_char->c = let;
	def_char->next = NULL;
	return (def_char);
}

void	ft_join_let(t_char **head, t_char *new_let)
{
	t_char	*temp;

	if (!new_let)
		return ;
	if (!*head)
	{
		*head = new_let;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_let;
}

char	*ft_clear_nodes(t_char *str)
{
	t_char	*temp;

	temp = str;
	while (temp)
	{
		temp = temp->next;
		free (str);
		str = temp;
	}
	temp = NULL;
	return (NULL);
}
