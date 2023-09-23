/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:58:38 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/21 13:19:20 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int	main(void)
{
	t_list *list = NULL;

    // Create nodes
    t_list *node1 = malloc(sizeof(t_list));
    node1->content = (void *)1;
    node1->next = NULL;

    t_list *node2 = malloc(sizeof(t_list));
    node2->content = (void *)2;
    node2->next = NULL;

    t_list *node3 = malloc(sizeof(t_list));
    node3->content = (void *)3;
    node3->next = NULL;

    // Add nodes to the list
    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node3);

	while (list != NULL) {
        printf("%d ", list->content);
        list = list->next;
    }
    printf("\n");
	t_list *ptr = node3;
	printf("%d\n", ft_lstsize(ptr));
	
	// Free memory
    free(node1);
    free(node2);
    free(node3);
	return (0);
	return (0);
}*/
