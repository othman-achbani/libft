/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:50:06 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/17 16:11:21 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunbr_helper(unsigned int n, int *res)
{
	if (n >= 10)
	{
		ft_putunbr_helper(n / 10, res);
		ft_putunbr_helper(n % 10, res);
	}
	else
		*res += ft_putchar(n + '0');
}

int	ft_putunbr(unsigned int n)
{
	int	res;

	res = 0;
	ft_putunbr_helper(n, &res);
	return (res);
}
