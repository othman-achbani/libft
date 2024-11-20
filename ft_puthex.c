/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 09:59:38 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/17 16:11:06 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_helper(unsigned int n, int i, int *res)
{
	if (n > 15)
	{
		ft_puthex_helper(n / 16, i, res);
		ft_puthex_helper(n % 16, i, res);
	}
	else
	{
		if (n < 10)
			*res += ft_putchar(n + '0');
		else if (i)
			*res += ft_putchar(n - 10 + 65);
		else
			*res += ft_putchar(n - 10 + 97);
	}
}

int	ft_puthex(unsigned int n, int i)
{
	int	res;

	res = 0;
	ft_puthex_helper(n, i, &res);
	return (res);
}
