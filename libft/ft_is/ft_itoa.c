/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:52:08 by afloris           #+#    #+#             */
/*   Updated: 2025/09/11 14:48:48 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		nb_digit;
	long	nb;

	nb = n;
	nb_digit = count_digit(n);
	s = (char *)malloc(sizeof (char) * (nb_digit + 1));
	if (!s)
		return (NULL);
	s[nb_digit] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
	{
		s[0] = '0';
	}
	while (nb > 0)
	{
		s[--nb_digit] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
