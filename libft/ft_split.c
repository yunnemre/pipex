/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:04:43 by ydinler           #+#    #+#             */
/*   Updated: 2025/06/14 18:55:27 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	ft_copy(char **res, char const *s, char c)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	start = 0;
	while (s[start])
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
		{
			res[i] = ft_substr(s, start, end - start);
			if (!res[i++])
				return (i);
		}
		start = end;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res;
	int		i;

	words = ft_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = ft_copy(res, s, c);
	if (i)
	{
		while (i--)
			free(res[i]);
		free(res);
		return (NULL);
	}
	res[words] = NULL;
	return (res);
}
