/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:49:40 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/18 18:49:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(long long int n, char *base)
{
	int					len;
	unsigned long int	base_len;
	char				*hexalower;

	hexalower = "0123456789abcdef";
	len = 0;
	base_len = ft_strlen(base);
	if (n == 0)
		len += ft_putstr_fd("(nil)", 1);
	else if (base == hexalower)
	{
		len += ft_putstr_fd("0x", 1);
		len += ft_put_unsigned_nbr(n, HEXL);
	}
	else
	{
		len += ft_putstr_fd("0x", 1);
		len += ft_putnbrbase(n, HEXU);
	}
	return (len);
}
