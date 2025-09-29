/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:51:29 by afloris           #+#    #+#             */
/*   Updated: 2025/09/11 14:48:48 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	count;

	count = 0;
	if (!s || !*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

void	my_free(char **str, size_t i)
{
	while (i > 0)
	{
		free(str[--i]);
	}
	free(str);
}

char	*skip_char(char *s, char c)
{
	while (*s == c && *s != '\0')
		s++;
	return (s);
}

char	*extract_substring(char *s, char c)
{
	char	*start;
	char	*end;
	char	*substring;
	size_t	len;

	start = skip_char(s, c);
	end = ft_strchr(start, c);
	if (!end)
	{
		end = start + ft_strlen(start);
	}
	len = end - start;
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (NULL);
	ft_memcpy(substring, start, len);
	substring[len] = '\0';
	return (substring);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	word_count;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	word_count = ft_countwords(s, c);
	res = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s && i < word_count)
	{
		s = skip_char((char *)s, c);
		res[i] = extract_substring((char *)s, c);
		if (!res[i])
		{
			my_free(res, i);
			return (NULL);
		}
		s += ft_strlen(res[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}
