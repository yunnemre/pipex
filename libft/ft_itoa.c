/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:42:32 by ydinler           #+#    #+#             */
/*   Updated: 2025/06/14 18:52:59 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_step(long n)
{
	int	step;

	step = 0;
	if (n <= 0)
		step++;
	while (n)
	{
		n /= 10;
		step++;
	}
	return (step);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		step;
	long	num;

	num = (long)n;
	step = ft_count_step(num);
	res = (char *)malloc(step + 1);
	if (!res)
		return (NULL);
	res[step] = '\0';
	if (num < 0)
	{
		num *= -1;
		res[0] = '-';
	}
	else if (num == 0)
		res[0] = '0';
	while (num)
	{
		res[--step] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
