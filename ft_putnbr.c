/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:57:35 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/17 16:11:08 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printnb_helper(int n, int *res)
{
	if (n < 0)
	{
		*res += ft_putchar('-');
		n = -n;
		ft_printnb_helper(n, res);
	}
	else if (n >= 10)
	{
		ft_printnb_helper(n / 10, res);
		ft_printnb_helper(n % 10, res);
	}
	else
		*res += ft_putchar(n + '0');
}

int	ft_printnb(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
	{
		res += ft_putstr("-2147483648");
		return (res);
	}
	ft_printnb_helper(n, &res);
	return (res);
}
