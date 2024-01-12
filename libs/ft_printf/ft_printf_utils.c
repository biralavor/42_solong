/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:33:49 by umeneses          #+#    #+#             */
/*   Updated: 2023/11/09 17:27:45 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_placeholder(char format, va_list ptr)
{
	int	len;

	len = 0;
	if ('c' == format)
		len += ft_putchar_fd(va_arg(ptr, int), 1);
	else if ('s' == format)
		len += ft_putstr_fd(va_arg(ptr, char *), 1);
	else if (('i' == format) || ('d' == format))
		len += ft_putnbrbase(va_arg(ptr, int), DEC);
	else if ('u' == format)
		len += ft_putnbr_fd(va_arg(ptr, unsigned int), 1);
	else if ('%' == format)
		len += ft_putchar_fd(37, 1);
	else if ('x' == format)
		len += ft_putnbrbase((long long)va_arg(ptr, unsigned int), HEXL);
	else if ('X' == format)
		len += ft_putnbrbase((long long)va_arg(ptr, unsigned int), HEXU);
	else if ('p' == format)
		len += ft_putptr((long long)va_arg(ptr, long long), HEXL);
	return (len);
}

int	ft_putnbrbase(long long int n, char *base)
{
	int				len;
	unsigned int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		len += ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= base_len)
		len += ft_putnbrbase((n / base_len), base);
	len += ft_putchar_fd(base[n % base_len], 1);
	return (len);
}

int	ft_put_unsigned_nbr(unsigned long long int n, char *base)
{
	int				len;
	unsigned int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		len += ft_putnbrbase((n / base_len), base);
	len += ft_putchar_fd(base[n % base_len], 1);
	return (len);
}

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
