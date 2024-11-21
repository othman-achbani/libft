/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:54:35 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/06 17:18:24 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && s2)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	if (!(n - i))
		return (0);
	return ((unsigned char )s1[i] - (unsigned char)s2[i]);
}
