/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:22:27 by fekiz             #+#    #+#             */
/*   Updated: 2023/10/22 16:09:59 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(int c);
size_t	ft_strlen(const char *str);
int		ft_count(int c);
int		ft_itoa(int n);
int		ft_type(va_list lst, char c);
int		ft_uns_itoa(unsigned int n);
int		ft_uns_count(unsigned int n);
int		ft_hex(unsigned int x, int b);
int		ft_pointer(unsigned long p);
int		ft_printf(const char *s, ...);
int		ft_type_two(va_list lst, char c);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strdup(const char *str);

#endif
