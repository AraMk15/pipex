/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:04:54 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/08 17:06:25 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_1;
	unsigned char		*ptr_2;

	ptr_1 = (const unsigned char *)src;
	ptr_2 = (unsigned char *)dest;
	if (ptr_2 <= ptr_1)
		ft_memcpy(ptr_2, ptr_1, n);
	else
	{
		ptr_2 += n;
		ptr_1 += n;
		while (n--)
			*(--ptr_2) = *(--ptr_1);
	}
	return (dest);
}
