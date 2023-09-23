/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:45:18 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/15 19:30:05 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*ptr;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, nitems * size);
	return (ptr);
}
/*
what if nimtes = -1?
int	main(void)
{
	int size = 0;
	int	*ptr = ft_calloc(0, size);
	int i = 0;
	printf("original:\n");
	while (i < size)
		printf("%d", ptr[i++]);
	printf("\ncopy:\n");
	i = 0;
	while (i < size)
		printf("%d", ptr[i++]);
	return (0);
}*/
