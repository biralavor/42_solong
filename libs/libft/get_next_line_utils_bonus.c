/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:24:20 by umeneses          #+#    #+#             */
/*   Updated: 2023/09/29 17:12:34 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t n_items, size_t size)
{
	void	*result;
	int		safety_arg;
	size_t	int_min;

	if (n_items == 0 && size == 0)
		return (malloc(0));
	int_min = -2147483648;
	if (n_items == int_min || size == int_min)
		return (NULL);
	safety_arg = n_items * size;
	if (safety_arg != 0 && (safety_arg / n_items) != size)
		return (NULL);
	result = malloc(safety_arg);
	if (!result)
		return (NULL);
	ft_memset(result, 0, safety_arg);
	return (result);
}

void	*ft_memset(void *str, int c, size_t size)
{
	int				index;
	unsigned char	*newstr;

	newstr = (unsigned char *)str;
	index = 0;
	while (size > 0)
	{
		newstr[index] = (unsigned char)c;
		size--;
		index++;
	}
	return (newstr);
}

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
