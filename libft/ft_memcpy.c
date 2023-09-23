/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:09:57 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/22 19:32:10 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_ptr;
	const char	*src_ptr;

	if (!dest && !src)
		return (NULL);
	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return ((void *)dest_ptr);
}

/*
int	main(void)
{
	char	src1[] = "hola mundo";
	char	src2[] = "hola mundo";
	char	dest1[0XF0];
	//char	dest2[] = "12345abcde";
	size_t	n = strlen(src1);

	printf("%s\n", (char *)ft_memcpy(dest1, src1, n));
	printf("%s\n", (char *)memcpy(dest1, src2, n));

	if (ft_memcpy(dest1, src1, n) == memcpy(dest1, src2, n))
		printf("\nSAME!\n");

	//printf("second:\n%s\n", (char *)ft_memcpy(((void*)0), ((void*)0), 3));
	printf("%s\n", (char *)memcpy(((void*)0), ((void*)0), 3));
	return (0);
}*/
