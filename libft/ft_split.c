/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:11:07 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/12 14:45:09 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c, size_t len)
{
	size_t	count_w;
	size_t	is_word;
	size_t	i;

	count_w = 0;
	is_word = 0;
	i = 0;
	while (i < len)
	{
		if (s[i] != c && !is_word)
		{
			count_w++;
			is_word = 1;
		}
		else if (s[i] == c)
			is_word = 0;
		i++;
	}
	return (count_w);
}

static void	ft_free_words(char **ptr, size_t j)
{
	while (j > 0)
		free(ptr[--j]);
	free(ptr);
}

static char	**ft_words(char const *s, char c, size_t len, char **ptr)
{
	size_t	i;
	size_t	j;
	size_t	count_s;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (s[i] != c)
		{
			count_s = 0;
			while (s[i + count_s] != c && s[i + count_s] != '\0')
				count_s++;
			ptr[j] = (char *)malloc(count_s + 1);
			if (!ptr[j])
				return (ft_free_words(ptr, j), NULL);
			ft_strlcpy(ptr[j++], &s[i], count_s + 1);
			i += count_s;
		}
		else
			i++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	len;
	size_t	count_w;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	count_w = ft_count_word(s, c, len);
	ptr = (char **)malloc(sizeof(char *) * (count_w + 1));
	if (!ptr)
		return (NULL);
	return (ft_words(s, c, len, ptr));
}
