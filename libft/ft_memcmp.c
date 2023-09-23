/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:20:43 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/11 10:37:32 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5};
	int	arr2[] = {1, 2, 3, 4, 5};
	int	n = sizeof(int) * 23;
	printf("%d\n\n", memcmp(arr, arr2, n));
	printf("%d", ft_memcmp(arr, arr2, n));
	return (0);
}*/
