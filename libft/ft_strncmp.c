/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:07:09 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/08 18:22:10 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;

	i = 0;
	ptr_1 = (unsigned char *)s1;
	ptr_2 = (unsigned char *)s2;
	while ((ptr_1[i] != '\0' || ptr_2[i] != '\0') && (i < n))
	{
		if (ptr_1[i] == ptr_2[i])
			i++;
		else
			return ((int)(ptr_1[i] - ptr_2[i]));
	}
	return (0);
}
