/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:50:34 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/08 17:13:29 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	u;

	i = ft_strlen(s);
	u = (char)c;
	while (i > 0)
	{
		if (s[i - 1] == u)
			return ((char *)(s + i - 1));
		i--;
	}
	i = ft_strlen(s);
	if (u == '\0')
		return ((char *)(s + i));
	return (NULL);
}
