/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:59:37 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/23 16:35:48 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (lst)
	{
		if (*lst)
		{
			curr = *lst;
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new;
		}
		else
			*lst = new;
	}
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
    printf("add start:\n");
    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node3);

	while (list != NULL) {
        printf("%d ", list->content);
        list = list->next;
    }
    printf("\n");

	// Test size
	t_list *ptrs = node3;
	printf("size:%d\n", ft_lstsize(ptrs));

	// Test add to last
	t_list *ptr2 = node3;
	t_list *node4 = malloc(sizeof(t_list));
	node4->content = (void *)4;
	node4->next = NULL;
	ft_lstadd_back(((void*)0), node4);
    printf("add end:\n");
	while (ptr2 != NULL) {
        printf("%d ", ptr2->content);
        ptr2 = ptr2->next;
    }
    printf("\n");

	// Test size
	t_list *ptr = node3;
	printf("size:%d\n", ft_lstsize(ptr));

	// Test last
	t_list *ptr3 = node3;
	t_list *last = ft_lstlast(ptr3);
	printf("last:%d\n", last->content);	

	// Free memory
    free(node1);
    free(node2);
    free(node3);
    free(node4);
	return (0);
}*/
