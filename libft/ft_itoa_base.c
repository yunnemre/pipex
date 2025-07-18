/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:11:24 by ydinler           #+#    #+#             */
/*   Updated: 2025/06/26 19:45:16 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_base_len(long long nbr, int base_len)
{
	int	len;

	len = (nbr <= 0);
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

static char	*ft_itoa_dec(int nbr, char *base)
{
	int		len;
	int		base_len;
	char	*res;
	long	n;

	base_len = ft_strlen(base);
	n = (long)nbr;
	len = get_base_len(n, base_len);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	else if (n == 0)
		res[0] = '0';
	while (n)
	{
		res[--len] = base[n % base_len];
		n /= base_len;
	}
	return (res);
}

static char	*ft_itoa_hex(long long nbr, char *base)
{
	int					len;
	size_t				base_len;
	char				*res;
	char				*sub;

	base_len = ft_strlen(base);
	len = base_len;
	res = ft_calloc(sizeof(char), (base_len + 1));
	if (!res)
		return (0);
	if (nbr == 0)
		res[--len] = '0';
	while (nbr)
	{
		res[--len] = base[nbr % base_len];
		nbr /= base_len;
	}
	sub = ft_substr(&res[len], 0, base_len - len);
	free(res);
	return (sub);
}

int	ft_itoa_man(va_list arg, char *base, char fmt)
{
	char			*str;
	size_t			len;
	long long		ptr;

	if (fmt == 'd' || fmt == 'i')
		str = ft_itoa_dec(va_arg(arg, int), base);
	else if (fmt == 'u' || fmt == 'x' || fmt == 'X')
		str = ft_itoa_hex(va_arg(arg, unsigned int), base);
	else if (fmt == 'p')
	{
		ptr = (long long)va_arg(arg, void *);
		if (ptr == 0)
		{
			(write(1, "(nil)", 5));
			return (3);
		}
		str = ft_itoa_hex(ptr, base);
		write(1, "0x", 2);
	}
	else
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
