/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:45:17 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/06 19:34:06 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	ptr_1 = (unsigned char *)src;
	ptr_2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		ptr_2[i] = ptr_1[i];
		i++;
	}
	return (ptr_2);
}
