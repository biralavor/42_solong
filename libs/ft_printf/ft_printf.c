/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:33:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/16 16:40:31 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

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

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		len;
	int		index;

	if (!format)
		return (-1);
	len = 0;
	index = 0;
	va_start(ptr, format);
	while (format[index])
	{
		if (format[index] == '%' && format[index + 1] != '\0')
			len += ft_placeholder(format[++index], ptr);
		else
			len += ft_putchar_fd(format[index], 1);
		index++;
	}
	va_end(ptr);
	return (len);
}
