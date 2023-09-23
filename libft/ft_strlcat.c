/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:20:06 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/23 17:22:17 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	r;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	r = dst_len;
	if (dst_len < size - 1 && size > 0)
	{
		while (src[i] && dst_len + i < size - 1)
		{
			dst[r] = src[i];
			i++;
			r++;
		}
		dst[r] = '\0';
	}
	if (dst_len >= size)
		return (size + src_len);
	return (dst_len + src_len);
}
/*
#include <bsd/string.h>
int	main(void)
{
	const char	src[] = "abcdefg123";
	char		dst[] = "123";
	//size_t		size = ft_strlen(src) + 1 + ft_strlen(dst);
	size_t		size = -1;
	const char	src2[] = "abcdefg123";
	char		dst2[] = "123";

	printf("original:\n dst: %s\n return: %zu\n", dst, strlcat(dst, src, size));
	printf("copy:\n dst: %s\n return: %zu\n", dst2, ft_strlcat(dst2, src2, size));
	
	//printf("size: %zu\nr: %zu\ndst: %s", size, ft_strlcat(dst, src, size), dst);
	return (0);
}
*/
/*
Reproduce the behavior of the
function strlcat
*/
/*
NOTES:
 - strlcat(char *dst, const char *src, size_t size)
 - strlcat() takes the full size of the buffer,
   not just length (includes nuls).
 - if there is at least one free byte in dst
   after concatenating, strlcat alwats terminates
   dst with null.
 - both src and dst must be nul-terminated
 - it will append at most
   size - length of src - 1 bytes
 - it returns the total length of the string
   it tried to create. This means original
   length of dst + length of src
 - WARNING: if no nul char are find in src
   within the inputed size, dst wont be
   nul-terminated.
*/
