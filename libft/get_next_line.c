/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:15:27 by ydinler           #+#    #+#             */
/*   Updated: 2025/06/25 19:53:57 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	free((void *)s1);
	if (ft_strlcat(res, s2, len) == len - 1)
		return (res);
	free(res);
	return (NULL);
}

static char	*ft_next_stash(char *stash)
{
	size_t	size;
	char	*res;
	char	*stash_temp;
	int		i;

	if (!ft_strchr(stash, '\n'))
	{
		free(stash);
		return (ft_strdup(""));
	}
	i = 0;
	stash_temp = ft_strchr(stash, '\n') + 1;
	size = ft_strlen(stash_temp);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	while (stash_temp[i])
	{
		res[i] = stash_temp[i];
		i++;
	}
	res[i] = '\0';
	free(stash);
	return (res);
}

static char	*ft_edit_stash(char *stash)
{
	char	*line;
	int		size;
	int		i;

	if (!ft_strchr(stash, '\n'))
		return (ft_strdup(stash));
	i = 0;
	size = (ft_strchr(stash, '\n') + 1) - stash;
	line = malloc(size + 1);
	if (!line)
		return (NULL);
	while (i < size)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_readline(int fd, char *stash)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while ((stash == NULL || !ft_strchr(stash, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		if (!stash && *buff)
			stash = ft_strdup(buff);
		else if (stash && *buff)
			stash = ft_strjoin_free(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	stash = ft_readline(fd, stash);
	if (!stash || *stash == '\0')
	{
		free(stash);
		return (NULL);
	}
	line = ft_edit_stash(stash);
	if (!line && !ft_strchr(line, '\n'))
		return (NULL);
	stash = ft_next_stash(stash);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
