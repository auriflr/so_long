/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:47:54 by babyf             #+#    #+#             */
/*   Updated: 2025/09/11 14:49:38 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

void	ft_putptr(unsigned long ptr, int *count)
{
	unsigned long		address;

	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	address = (unsigned long)ptr;
	ft_putstr("0x", count);
	ft_putnbr_unsigned(address, 16, "0123456789abcdef", count);
}

void	conversion_check(char c, int *count, va_list args)
{
	char	*hex_digits;

	if (c == 'c')
		ft_putchr(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
		ft_putptr(va_arg(args, unsigned long), count);
	else if (c == 'i' || c == 'd')
		ft_putnbr_signed(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), 10, "0123456789", count);
	else if (c == 'x')
	{
		hex_digits = "0123456789abcdef";
		ft_putnbr_unsigned(va_arg(args, unsigned int), 16, hex_digits, count);
	}
	else if (c == 'X')
	{
		hex_digits = "0123456789ABCDEF";
		ft_putnbr_unsigned(va_arg(args, unsigned int), 16, hex_digits, count);
	}
	else if (c == '%')
		ft_putchr('%', count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			conversion_check(*format, &count, args);
		}
		else
			ft_putchr(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
