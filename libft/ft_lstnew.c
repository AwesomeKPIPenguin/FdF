/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:51:23 by domelche          #+#    #+#             */
/*   Updated: 2017/11/01 16:51:25 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(node->content = malloc(content_size)))
			return (NULL);
		node->content = ft_memmove(node->content, content, content_size);
	}
	else
	{
		node->content = NULL;
		content_size = 0;
	}
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}
