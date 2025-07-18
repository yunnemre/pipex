/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:01:42 by ydinler           #+#    #+#             */
/*   Updated: 2025/06/14 21:43:28 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		lt_len;
	size_t		i;

	i = 0;
	lt_len = ft_strlen(little);
	if (lt_len == 0)
		return ((char *)big);
	while (big[i] && len - i >= lt_len)
	{
		if (!ft_strncmp(&big[i], little, lt_len))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
