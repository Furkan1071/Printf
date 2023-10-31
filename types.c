/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:18:46 by fekiz             #+#    #+#             */
/*   Updated: 2023/10/22 14:27:55 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp_dst;
	char	*tmp_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (dst);
}

int	ft_putstr(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!(str))
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_type(va_list lst, char c)
{
	int		count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(lst, int));
	else if (c == 's')
		count += ft_putstr(va_arg(lst, char *));
	else if (c == 'd' || c == 'i')
		count += ft_itoa(va_arg(lst, int));
	else if (c == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_pointer(va_arg(lst, unsigned long));
	}
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'u')
		count += ft_uns_itoa(va_arg(lst, int));
	else if (c == 'x')
		count += ft_hex(va_arg(lst, unsigned int), 0);
	else if (c == 'X')
		count += ft_hex(va_arg(lst, unsigned int), 1);
	return (count);
}
