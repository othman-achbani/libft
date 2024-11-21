/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:39 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/06 16:45:15 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		slen;
	int			i;
	size_t		d;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= (unsigned int)slen)
		return (ft_strdup("\0"));
	else if (len > slen)
		p = ft_calloc(slen + 1, sizeof(char));
	else
		p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	d = 0;
	i = -1;
	while (s[++i])
		if (start <= (unsigned int) i && d < len)
			p[d++] = s[i];
	return (p);
}
