/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:55:37 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/17 16:11:15 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_ptr_help(unsigned long long i, int *res)
{
	if (i > 15)
	{
		ft_print_ptr_help(i / 16, res);
		ft_print_ptr_help(i % 16, res);
	}
	else
	{
		if (i < 10)
			*res += ft_putchar(i + 48);
		else
			*res += ft_putchar(i - 10 + 97);
	}
}

int	ft_print_ptr(void *p)
{
	int					res;
	unsigned long long	i;

	i = (unsigned long long)p;
	res = 0;
	if (!i)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	res += 2;
	ft_print_ptr_help(i, &res);
	return (res);
}
