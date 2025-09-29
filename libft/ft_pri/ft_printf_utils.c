/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:32:49 by babyf             #+#    #+#             */
/*   Updated: 2025/09/22 17:14:12 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

void	ft_putchr(int c, int *count)
{
	write (1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *s, int *count)
{
	if (!s)
		s = "(null)";
	while (*s)
		ft_putchr(*s++, count);
}

void	ft_putnbr_signed(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putstr("-", count);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_signed(n / 10, count);
	ft_putchr((n % 10) + '0', count);
}

void	ft_putnbr_unsigned(unsigned long n, int base, char *digits, int *count)
{
	if (n >= (unsigned long)base)
		ft_putnbr_unsigned(n / base, base, digits, count);
	ft_putchr(digits[n % base], count);
}
