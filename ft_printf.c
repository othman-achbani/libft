/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:15:25 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/18 11:01:07 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkformat(char c, va_list ptr)
{
	int	res;

	res = 0;
	if (c == 'c')
		res += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		res += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		res += ft_print_ptr(va_arg(ptr, void *));
	else if (c == 'd' || c == 'i')
		res += ft_printnb(va_arg(ptr, int));
	else if (c == 'u')
		res += ft_putunbr(va_arg(ptr, int));
	else if (c == 'x')
		res += ft_puthex(va_arg(ptr, unsigned int), 0);
	else if (c == 'X')
		res += ft_puthex(va_arg(ptr, unsigned int), 1);
	else if (c == '%')
		res += ft_putchar('%');
	else
		return (-1);
	return (res);
}

static int	ft_vaprintf(const char *s, va_list ptr)
{
	int	i;
	int	res;
	int	check;

	check = 0;
	res = 0;
	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			check = ft_checkformat(s[i + 1], ptr);
			if (check < 0)
				return (-1);
			res += check;
			check = 0;
			i++;
		}
		else
			res += ft_putchar(s[i]);
	}
	return (res);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		res;

	res = 0;
	if (!s || (s[0] == '%' && !s[1]))
		return (-1);
	va_start(ptr, s);
	res = ft_vaprintf(s, ptr);
	va_end(ptr);
	return (res);
}
