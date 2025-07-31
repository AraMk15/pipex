/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:59:10 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/06 21:44:09 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!dst && !src)
		return (ft_strlen(dst));
	i = 0;
	j = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize < j)
		return (ft_strlen(src) + dstsize);
	while ((j + i) < dstsize - 1 && src[i] != '\0')
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (ft_strlen(src) + j);
}
