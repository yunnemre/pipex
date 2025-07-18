/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:30:56 by ydinler           #+#    #+#             */
/*   Updated: 2025/06/26 17:22:33 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putstr(va_list args, int mod)
{
	size_t	len;
	int		c;
	char	*str;

	if (mod == 1)
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		return (1);
	}
	else if (mod == 2)
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		len = ft_strlen(str);
		write(1, str, len);
		return (len);
	}
	return (0);
}
