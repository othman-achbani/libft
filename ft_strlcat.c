/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:33:51 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/06 16:41:45 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i ;
	size_t	ret;
	size_t	s;
	size_t	d;

	if (!size && src)
		return (ft_strlen(src));
	d = ft_strlen(dest);
	i = 0;
	s = ft_strlen(src);
	if (size > d)
		ret = d + s;
	else
		ret = s + size;
	while (d + i < size - 1 && src[i])
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (ret);
}
