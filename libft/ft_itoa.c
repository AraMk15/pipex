/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:00:52 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/12 14:41:42 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_ptr(char *ptr, size_t len, int n)
{
	if (n == 0)
	{
		ptr[0] = '0';
		return (ptr);
	}
	while (n != 0)
	{
		ptr[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len(n);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	ft_ptr(ptr, len, n);
	return (ptr);
}
