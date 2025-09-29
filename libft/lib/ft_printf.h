/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:43:35 by babyf             #+#    #+#             */
/*   Updated: 2025/03/31 16:03:31 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchr(int c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr_unsigned(unsigned long n, int base, char *digits, int *count);
void	ft_putptr(unsigned long ptr, int *count);
void	ft_putnbr_signed(int n, int *count);
int		ft_printf(const char *format, ...);

#endif
