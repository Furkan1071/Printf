/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:46 by fekiz             #+#    #+#             */
/*   Updated: 2023/10/21 14:33:14 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uns_count(unsigned int n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_uns_itoa(unsigned int n)
{
	int		digit;
	char	*str;

	digit = ft_uns_count(n);
	str = malloc(digit + 1);
	if (!str)
		return ('\0');
	str[digit--] = '\0';
	if (n == 0)
		str[digit] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[digit--] = n % 10 + 48;
		n = n / 10;
	}
	n = write(1, str, ft_strlen(str));
	free(str);
	return (n);
}
