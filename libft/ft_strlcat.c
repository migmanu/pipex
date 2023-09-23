/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:20:06 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/09/23 17:25:11 by jmigoya-         ###   ########.fr       */
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
