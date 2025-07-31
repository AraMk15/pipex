/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:07:58 by armkrtch          #+#    #+#             */
/*   Updated: 2025/02/11 23:18:11 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_re(t_list **node, void (*del)(void*))
{
	if (!*node)
		return ;
	ft_re(&((*node)->next), del);
	del((*node)->content);
	free(*node);
	*node = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	ft_re(lst, del);
	lst = NULL;
}
