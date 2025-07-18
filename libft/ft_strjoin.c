/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:56:27 by ydinler           #+#    #+#             */
/*   Updated: 2025/06/02 15:02:48 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1);
	len += ft_strlen(s2) + 1;
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len);
	if (ft_strlcat(res, s2, len) == len - 1)
		return (res);
	return (NULL);
}
