/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:59:27 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/08 17:01:44 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		smy;
	size_t				i;

	ptr = (const unsigned char *)s;
	smy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == smy)
			return ((void *)(&ptr[i]));
		i++;
	}
	return (NULL);
}
