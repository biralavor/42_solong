/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:03:14 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/18 17:06:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define DEC "0123456789"
# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	ft_placeholder(char format, va_list ptr);
int	ft_putnbrbase(long long int n, char *base);
int	ft_putptr(long long int n, char *base);
int	ft_put_unsigned_nbr(unsigned long long int n, char *base);
int	ft_putchar_fd(int c, int fd);

#endif