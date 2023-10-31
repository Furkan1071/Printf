/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:46 by fekiz             #+#    #+#             */
/*   Updated: 2023/10/21 16:19:31 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count(int c)
{
	int		count;
	long	num;

	num = c;
	count = 0;
	if (c == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		count++;
	}
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_itoa(int n)
{
	int		digit;
	long	nbr;
	char	*str;

	nbr = n;
	digit = ft_count(nbr);
	str = malloc(digit + 1);
	if (!str)
		return ('\0');
	str[digit--] = '\0';
	if (nbr == 0)
		str[digit] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[digit--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	nbr = write(1, str, ft_strlen(str));
	free(str);
	return (nbr);
}
