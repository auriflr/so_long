/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:47:28 by afloris           #+#    #+#             */
/*   Updated: 2025/10/18 10:36:18 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static char	*ft_bytes(char **tmp, char *buf, int bytes_read)
{
	char	*ret;

	if (bytes_read <= 0)
	{
		if (*tmp && **tmp)
		{
			ret = *tmp;
			*tmp = NULL;
			free(buf);
			return (ret);
		}
		free(buf);
		free(*tmp);
		*tmp = NULL;
		return (NULL);
	}
	if (bytes_read > 0)
	{
		free (buf);
		free (*tmp);
		*tmp = NULL;
		return (NULL);
	}
	return (NULL);
}

static char	*ft_nl_buf(char **tmp, char *buf)
{
	char	*ret;
	char	*new_pos;
	char	*substr;

	new_pos = ft_strchr(buf, '\n');
	substr = ft_substr(buf, 0, new_pos - buf + 1);
	if (*tmp)
	{
		ret = ft_strjoin(*tmp, substr);
		free(*tmp);
		free(substr);
		*tmp = ft_strdup(new_pos + 1);
	}
	else
	{
		ret = substr;
		*tmp = ft_strdup(new_pos + 1);
	}
	free(buf);
	return (ret);
}

static char	*ft_nl_tmp(char **tmp, char *buf)
{
	char	*new_pos;
	char	*ret;
	char	*old_tmp;

	new_pos = ft_strchr(*tmp, '\n');
	ret = ft_substr(*tmp, 0, new_pos - *tmp + 1);
	old_tmp = *tmp;
	*tmp = ft_strdup(new_pos + 1);
	free(old_tmp);
	free(buf);
	return (ret);
}

static void	ft_append(char **tmp, char *buf)
{
	char	*old_tmp;

	if (*tmp)
	{
		old_tmp = *tmp;
		*tmp = ft_strjoin(old_tmp, buf);
		free(old_tmp);
	}
	else
		*tmp = ft_strdup(buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			bytes_read;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (1)
	{
		if (tmp && ft_strchr(tmp, '\n'))
			return (ft_nl_tmp(&tmp, buf));
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (ft_bytes(&tmp, buf, bytes_read));
		buf[bytes_read] = '\0';
		if (ft_strchr(buf, '\n'))
			return (ft_nl_buf(&tmp, buf));
		ft_append(&tmp, buf);
	}
}
