/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:36:37 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/21 18:47:10 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;

	while (*lst != NULL)
	{
		curr = *lst;
		del(curr->content);
		*lst = (*lst)->next;
		free(curr);
	}
	lst = NULL;
}
/*
int	main(void)
{
	return (0);
}*/
