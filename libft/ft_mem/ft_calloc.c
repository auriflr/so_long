/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:28:25 by afloris           #+#    #+#             */
/*   Updated: 2025/09/11 14:48:48 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			tot_size;
	void			*ptr;

	if (size != 0 && count > ((size_t) - 1) / size)
		return (NULL);
	tot_size = count * size;
	ptr = malloc(tot_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, tot_size);
	return (ptr);
}
