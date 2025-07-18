/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_persent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:20:21 by ydinler           #+#    #+#             */
/*   Updated: 2025/06/24 19:07:19 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_check_persent(char c, va_list args)
{
	if (c == 'c')
		return (ft_putstr(args, 1));
	else if (c == 's')
		return (ft_putstr(args, 2));
	else if (c == 'p')
		return (ft_itoa_man(args, HEX_DOWN, c) + 2);
	else if (c == 'd' || c == 'i')
		return (ft_itoa_man(args, DECIMAL, c));
	else if (c == 'u')
		return (ft_itoa_man(args, DECIMAL, c));
	else if (c == 'x')
		return (ft_itoa_man(args, HEX_DOWN, c));
	else if (c == 'X')
		return (ft_itoa_man(args, HEX_UP, c));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
