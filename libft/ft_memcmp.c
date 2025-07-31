/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:02:01 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/08 17:04:27 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_1;
	const unsigned char	*ptr_2;
	size_t				i;

	ptr_1 = (const unsigned char *)s1;
	ptr_2 = (const unsigned char *)s2;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			if (ptr_1[i] != ptr_2[i])
				return (ptr_1[i] - ptr_2[i]);
			i++;
		}
	}
	return (0);
}
