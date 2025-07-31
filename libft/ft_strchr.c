/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:18:45 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/08 22:46:14 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	u;

	u = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == u)
			return ((char *)(s));
		s++;
	}
	if (u == '\0')
		return ((char *)(s));
	return (NULL);
}
