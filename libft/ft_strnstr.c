/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:09:17 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/08 17:11:25 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)(haystack));
	if (len > 0)
	{
		while (i < len && haystack[i] != '\0')
		{
			j = 0;
			while ((i + j < len) && (haystack[i + j] == needle[j]))
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)(haystack + i));
			}
			i++;
		}
	}
	return (NULL);
}
