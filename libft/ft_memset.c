/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:39:40 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/08 17:13:59 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*dst;

	dst = (char *)s;
	i = 0;
	while (i < n)
	{
		dst[i] = c;
		i++;
	}
	return ((void *)dst);
}
/*
#include <string.h>
int	main(void)
{
	char	s[20];
	char	s2[20];
	int		c = 128;
	size_t	n = 3;
	printf("%s\n", ft_memset(s, c, n));
	printf("%s\n", memset(s2, c, n));
	return (0);
}*/
