/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 03:08:03 by fekiz             #+#    #+#             */
/*   Updated: 2023/10/24 13:56:16 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*str2;

	str2 = malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	if (!str2)
		return (NULL);
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

static int	ft_check(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup("cdixXspu%");
	while (str[i])
	{
		if (str[i] == c)
		{
			free(str);
			return (1);
		}
		i++;
	}
	free(str);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	lst;

	i = 0;
	count = 0;
	va_start(lst, s);
	while (s[i] != '\0')
	{
		if ((s[i] == '%') && (ft_check(s[i + 1]) == 1))
		{
			i++;
			count += ft_type(lst, s[i++]);
		}
		else if ((s[i] == '%') && (ft_check(s[++i]) == 0))
			return (count);
		else
			count += write (1, &s[i++], 1);
	}
	va_end(lst);
	return (count);
}
