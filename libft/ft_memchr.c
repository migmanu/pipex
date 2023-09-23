/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:43:06 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/16 12:02:49 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(char *)(s + i) == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	int	s[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int	c = 2;

	char	str[] = "hola mundo!";
	char	cc = 'm';
	printf("original: %d\n\n", *((int *)memchr(s, c, 5)));
	printf("copy: %d\n\n", *((int *)ft_memchr(s, c, 5)));

	printf("original: %s\n\n", (char *)memchr(str, cc, 9));
	printf("copy: %s", (char *)ft_memchr(str, cc, 9));
	return (0);
}*/
