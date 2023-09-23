/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:14:07 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/22 19:51:30 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	printf("trial init\n");
	char *src = "thanks to @apellicc for this test !\r\n";
 	char dst1[0xF0];
 	int size = strlen(src);
 	char *r1 = memmove(dst1, src, size);
 	char *r2 = ft_memmove(dst1, src, size);
 
 	if (r1 != r2)
		printf("\nSAME 1\n");
 	r1 = memmove("", "" - 1, 0);
 	r2 = ft_memmove("", "" - 1, 0);
 	if (r1 != r2)
		printf("\nSAME 2\n");
	
	char b[0xF0];
 	ft_memmove(((void*)0), b, 5);
	return (0);
}*/
	/*
	size_t		n = 4;

	// test strings

	const char	src1[] = "123456789";
	char		dest1[] = "hola";

	const char	src2[] = "123456789";
	char		dest2[] = "hola";


	printf("Strings:\n\norig: %s\n", (char *)memmove(dest2, src2, n));
	printf("copy: %s\n", (char *)ft_memmove(dest1, src1, n));

	// tests arrays

	int	arr_src1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	arr_dest1[] = {11, 12, 13, 14, 15, 16, 17 ,18, 19};

	int	arr_src2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	arr_dest2[] = {11, 12, 13, 14, 15, 16, 17 ,18, 19};

	memmove(arr_dest1, arr_src1, sizeof(int) * n);
	ft_memmove(arr_dest2, arr_src2, sizeof(int) * n);

	printf("\narrays\noriginal:\nsrc:");

	size_t i = 0;
	while (i < 9)
		printf("%d,", arr_src1[i++]);

	printf("\ndest:");
	i = 0;
	while (i < 9)
		printf("%d,", arr_dest1[i++]);

	printf("\ncopy:\nsrc:");
	i = 0;
	while (i < 9)
		printf("%d,", arr_src2[i++]);

	printf("\ndest:");
	i = 0;
	while (i < 9)
		printf("%d,", arr_dest2[i++]);
	
	return (0);
}
*/
/*
 - memmove() copies bytes from src to dest, which may overlap
 - it does so using a temp array which does not overlap with
 - either src or dest.
 - It returns a pointer to dest
*/
