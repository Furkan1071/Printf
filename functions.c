/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:34:50 by fekiz             #+#    #+#             */
/*   Updated: 2023/10/22 14:13:40 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int x, int b)
{
	int	count;

	count = 0;
	if (x >= 16)
		count += ft_hex(x / 16, b);
	if ((x % 16) < 10)
		count += ft_putchar((x % 16) + '0');
	else
	{
		if (b == 0)
			count += ft_putchar((x % 16) + 87);
		else
			count += ft_putchar((x % 16) + 55);
	}
	return (count);
}

int	ft_pointer(unsigned long p)
{
	char	*base;
	int		count;
	int		i;

	count = 0;
	i = 0;
	base = ft_strdup("0123456789abcdef");
	if (p >= 16)
		count += ft_pointer(p / 16);
	count += write(1, &base[p % 16], 1);
	free(base);
	return (count);
}
